#ifndef SERIALSCANNER_H
#define SERIALSCANNER_H

#include <QObject>
#include <QByteArray>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>

class SerialScanner : public QObject
{
    Q_OBJECT

public:
    explicit SerialScanner(QObject *parent = nullptr);

    QStringList ports() const;
    QString portNameAt(int index) const;
    bool openPortByIndex(int index, qint32 baudRate = 115200);
    void closePort();
    bool isConnected() const;
    QString connectedPortName() const;
    QString lastError() const;
    bool sendCommand(const QString &command);
    bool sendCommands(const QStringList &commands);

public slots:
    void refreshPorts();

signals:
    void portsListChanged(const QStringList &ports);
    void connectionStateChanged(bool connected, const QString &portName);
    void lineReceived(const QString &line);
    void commandSent(const QString &line);
    void errorTextChanged(const QString &errorText);

private:
    void processIncomingData();

    QList<QSerialPortInfo> m_availablePorts;
    QStringList m_all_ports;
    QSerialPort m_current_port;
    QString m_lastError;
    QByteArray m_readBuffer;
};

#endif // SERIALSCANNER_H
