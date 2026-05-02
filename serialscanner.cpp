#include "serialscanner.h"

#include <QDebug>
#include <QIODevice>

SerialScanner::SerialScanner(QObject *parent)
    : QObject(parent)
    , m_current_port(this)
{
    // Как только от устройства приходят байты, дочитываем их и собираем в строки.
    connect(&m_current_port, &QSerialPort::readyRead,
            this, &SerialScanner::processIncomingData);
    connect(&m_current_port, &QSerialPort::errorOccurred,
            this, [this](QSerialPort::SerialPortError error) {
                if (error == QSerialPort::NoError) {
                    return;
                }

                m_lastError = m_current_port.errorString();
                emit errorTextChanged(m_lastError);

                // При потере устройства закрываем порт и сообщаем UI, что соединение оборвалось.
                if (error == QSerialPort::ResourceError) {
                    const QString portName = m_current_port.portName();
                    m_current_port.close();
                    emit connectionStateChanged(false, portName);
                }
            });
}

void SerialScanner::refreshPorts()
{
    m_availablePorts.clear();
    m_all_ports.clear();

    // Храним и объект порта, и человекочитаемую подпись для списка в интерфейсе.
    const auto allPorts = QSerialPortInfo::availablePorts();
    for (const auto &port : allPorts) {
        m_availablePorts.append(port);

        const QString description = port.description().trimmed().isEmpty()
            ? QStringLiteral("без описания")
            : port.description().trimmed();
        m_all_ports.append(QStringLiteral("%1 - %2").arg(port.portName(), description));
    }

    qDebug() << "Найдено портов:" << m_all_ports.size();
    emit portsListChanged(m_all_ports);
}

QStringList SerialScanner::ports() const
{
    return m_all_ports;
}

QString SerialScanner::portNameAt(int index) const
{
    if (index < 0 || index >= m_availablePorts.size()) {
        return {};
    }

    return m_availablePorts.at(index).portName();
}

bool SerialScanner::openPortByIndex(int index, qint32 baudRate)
{
    if (index < 0 || index >= m_availablePorts.size()) {
        m_lastError = QStringLiteral("Не выбран COM-порт.");
        emit errorTextChanged(m_lastError);
        return false;
    }

    if (m_current_port.isOpen()) {
        m_current_port.close();
    }

    const QSerialPortInfo &portInfo = m_availablePorts.at(index);
    m_current_port.setPort(portInfo);
    m_current_port.setBaudRate(baudRate);
    m_current_port.setDataBits(QSerialPort::Data8);
    m_current_port.setParity(QSerialPort::NoParity);
    m_current_port.setStopBits(QSerialPort::OneStop);
    m_current_port.setFlowControl(QSerialPort::NoFlowControl);

    if (!m_current_port.open(QIODevice::ReadWrite)) {
        m_lastError = m_current_port.errorString();
        emit errorTextChanged(m_lastError);
        emit connectionStateChanged(false, {});
        return false;
    }

    m_lastError.clear();
    m_readBuffer.clear();
    // После успешного открытия сбрасываем накопленный буфер и даём UI обновить статус.
    emit connectionStateChanged(true, portInfo.portName());
    return true;
}

void SerialScanner::closePort()
{
    if (!m_current_port.isOpen()) {
        return;
    }

    const QString portName = m_current_port.portName();
    m_current_port.close();
    m_readBuffer.clear();
    emit connectionStateChanged(false, portName);
}

bool SerialScanner::isConnected() const
{
    return m_current_port.isOpen();
}

QString SerialScanner::connectedPortName() const
{
    return m_current_port.isOpen() ? m_current_port.portName() : QString();
}

QString SerialScanner::lastError() const
{
    return m_lastError;
}

bool SerialScanner::sendCommand(const QString &command)
{
    if (!m_current_port.isOpen()) {
        m_lastError = QStringLiteral("Порт не подключен.");
        emit errorTextChanged(m_lastError);
        return false;
    }

    const QString normalizedCommand = command.trimmed();
    if (normalizedCommand.isEmpty()) {
        return false;
    }

    // Большинство G-code контроллеров ожидают команды построчно, поэтому добавляем '\n'.
    const QByteArray payload = normalizedCommand.toUtf8() + "\n";
    const qint64 bytesWritten = m_current_port.write(payload);
    if (bytesWritten == -1) {
        m_lastError = m_current_port.errorString();
        emit errorTextChanged(m_lastError);
        return false;
    }

    if (!m_current_port.waitForBytesWritten(500)) {
        m_lastError = m_current_port.errorString();
        emit errorTextChanged(m_lastError);
        return false;
    }

    emit commandSent(normalizedCommand);
    return true;
}

bool SerialScanner::sendCommands(const QStringList &commands)
{
    bool allSent = true;

    for (const QString &command : commands) {
        const QString trimmed = command.trimmed();
        if (trimmed.isEmpty()) {
            continue;
        }

        if (!sendCommand(trimmed)) {
            allSent = false;
            break;
        }
    }

    return allSent;
}

void SerialScanner::processIncomingData()
{
    m_readBuffer.append(m_current_port.readAll());

    // Разбираем входящий поток по строкам, чтобы UI получал готовые ответы платы.
    while (true) {
        const int lineEndIndex = m_readBuffer.indexOf('\n');
        if (lineEndIndex < 0) {
            break;
        }

        QByteArray line = m_readBuffer.left(lineEndIndex);
        m_readBuffer.remove(0, lineEndIndex + 1);

        if (!line.isEmpty() && line.endsWith('\r')) {
            line.chop(1);
        }

        emit lineReceived(QString::fromUtf8(line));
    }

    // Защита от бесконечного роста буфера, если устройство шлёт данные без переводов строки.
    if (m_readBuffer.size() > 4096) {
        emit lineReceived(QString::fromUtf8(m_readBuffer));
        m_readBuffer.clear();
    }
}
