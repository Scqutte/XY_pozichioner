#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QFile>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRegularExpression>
#include <QSpinBox>
#include <QStringList>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , channelGroup(new QButtonGroup(this))
    , serialScanner(new SerialScanner(this))
    , autoCycleTimer(new QTimer(this))
    , currentChannelIndex(0)
    , autoCycleSequencePosition(0)
    , autoCycleCompletedLoops(0)
    , currentPosition(0.0, 0.0)
    , hasKnownPosition(false)
    , autoCycleActive(false)
{
    ui->setupUi(this);
    autoCycleTimer->setSingleShot(false);
    ui->contentLayout->setColumnStretch(0, 5);
    ui->contentLayout->setColumnStretch(1, 6);
    ui->contentLayout->setRowStretch(0, 0);
    ui->contentLayout->setRowStretch(1, 1);
    ui->contentLayout->setRowStretch(2, 0);
    ui->controlsLayout->setAlignment(Qt::AlignTop);
    setupChannelButtons();
    setupStyles();
    initializeChannelPositions();
    setupConnections();
    applyChannelSelection(0);
    updateAutoCycleUi();
    refreshPortOnClick();
}

MainWindow::~MainWindow()
{
    if (serialScanner != nullptr) {
        serialScanner->closePort();
    }

    delete ui;
}

void MainWindow::setupStyles()
{
    ui->panelConnection->setObjectName("panelCard");
    ui->panelControls->setObjectName("panelCard");
    ui->panelGcode->setObjectName("panelCard");
    ui->panelLog->setObjectName("panelCard");
    ui->panelChannels->setObjectName("panelCard");
    ui->topLabel->setObjectName("sectionText");
    ui->connectionTitle->setObjectName("sectionTitle");
    ui->controlsTitle->setObjectName("sectionTitle");
    ui->gcodeTitle->setObjectName("sectionTitle");
    ui->logTitle->setObjectName("sectionTitle");
    ui->channelsTitle->setObjectName("sectionTitle");
    ui->stepLabel->setObjectName("sectionText");
    ui->channelsHint->setObjectName("sectionText");
    ui->autoCycleTitle->setObjectName("sectionTextStrong");
    ui->autoSequenceLabel->setObjectName("sectionText");
    ui->autoDelayLabel->setObjectName("sectionText");
    ui->autoRepeatLabel->setObjectName("sectionText");
    ui->labelSelectedChannel->setObjectName("sectionTextStrong");
    ui->labelStatus->setObjectName("statusBadge");
    ui->labelDetails->setObjectName("statusPanel");
    ui->labelCurrentPosition->setObjectName("statusPanel");
    ui->labelChannelPosition->setObjectName("statusPanel");
    ui->labelAutoCycleState->setObjectName("statusPanel");
    ui->centerLabel->setObjectName("moveCenterLabel");

    ui->btnRefresh->setObjectName("secondaryButton");
    ui->btnConnect->setObjectName("primaryButton");
    ui->btnSendGcode->setObjectName("primaryButton");
    ui->btnClearLog->setObjectName("secondaryButton");
    ui->btnMoveUp->setObjectName("secondaryButton");
    ui->btnMoveDown->setObjectName("secondaryButton");
    ui->btnMoveLeft->setObjectName("secondaryButton");
    ui->btnMoveRight->setObjectName("secondaryButton");
    ui->btnHome->setObjectName("secondaryButton");
    ui->btnStop->setObjectName("dangerButton");
    ui->btnRequestPosition->setObjectName("secondaryButton");
    ui->btnCapturePosition->setObjectName("secondaryButton");
    ui->btnExecuteChannel->setObjectName("primaryButton");
    ui->btnStartAutoCycle->setObjectName("primaryButton");
    ui->btnStopAutoCycle->setObjectName("dangerButton");

    QFile styleFile(":/styles/app.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        setStyleSheet(QString::fromUtf8(styleFile.readAll()));
    }
}

void MainWindow::setupChannelButtons()
{
    channelGroup->setExclusive(true);

    // Кнопки каналов храним в массиве, чтобы одинаково настраивать их и обновлять подписи.
    channelButtons = {
        ui->btnChannel1, ui->btnChannel2, ui->btnChannel3, ui->btnChannel4,
        ui->btnChannel5, ui->btnChannel6, ui->btnChannel7, ui->btnChannel8,
        ui->btnChannel9, ui->btnChannel10, ui->btnChannel11, ui->btnChannel12,
        ui->btnChannel13
    };

    for (int index = 0; index < channelButtons.size(); ++index) {
        channelButtons[index]->setObjectName(index == 0 ? "primaryButton" : "secondaryButton");
        channelButtons[index]->setProperty("channelButton", true);
        channelGroup->addButton(channelButtons[index], index);
    }
}

void MainWindow::setupConnections()
{
    connect(ui->btnRefresh, &QPushButton::clicked,
            this, &MainWindow::refreshPortOnClick);
    connect(ui->btnConnect, &QPushButton::clicked,
            this, &MainWindow::connectPortOnClick);
    connect(ui->btnSendGcode, &QPushButton::clicked,
            this, &MainWindow::sendGcodeOnClick);
    connect(ui->inputGcode, &QLineEdit::returnPressed,
            this, &MainWindow::sendGcodeOnClick);
    connect(ui->btnClearLog, &QPushButton::clicked,
            ui->terminalLog, &QPlainTextEdit::clear);

    connect(ui->btnMoveLeft, &QPushButton::clicked,
            this, [this]() { sendManualMove(-ui->spinMoveStep->value(), 0.0); });
    connect(ui->btnMoveRight, &QPushButton::clicked,
            this, [this]() { sendManualMove(ui->spinMoveStep->value(), 0.0); });
    connect(ui->btnMoveUp, &QPushButton::clicked,
            this, [this]() { sendManualMove(0.0, ui->spinMoveStep->value()); });
    connect(ui->btnMoveDown, &QPushButton::clicked,
            this, [this]() { sendManualMove(0.0, -ui->spinMoveStep->value()); });

    connect(ui->btnHome, &QPushButton::clicked,
            this, [this]() {
                if (autoCycleActive) {
                    stopAutoCycle(true);
                }

                if (!serialScanner->sendCommand("G28")) {
                    appendLogLine("ERR", serialScanner->lastError());
                    return;
                }
                setCurrentPosition(0.0, 0.0, false);
            });
    connect(ui->btnStop, &QPushButton::clicked,
            this, [this]() {
                if (autoCycleActive) {
                    stopAutoCycle(true);
                }

                if (!serialScanner->sendCommand("M112")) {
                    appendLogLine("ERR", serialScanner->lastError());
                }
            });

    connect(ui->btnRequestPosition, &QPushButton::clicked,
            this, [this]() { requestCurrentPosition(); });
    connect(ui->btnCapturePosition, &QPushButton::clicked,
            this, &MainWindow::captureCurrentPositionForChannel);
    connect(ui->btnExecuteChannel, &QPushButton::clicked,
            this, &MainWindow::executeCurrentChannel);
    connect(ui->btnStartAutoCycle, &QPushButton::clicked,
            this, &MainWindow::startAutoCycle);
    connect(ui->btnStopAutoCycle, &QPushButton::clicked,
            this, &MainWindow::stopAutoCycleOnClick);
    connect(ui->spinAutoDelayMs, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this](int delayMs) {
                if (autoCycleTimer->isActive()) {
                    autoCycleTimer->setInterval(delayMs);
                }
                updateAutoCycleUi();
            });
    connect(ui->spinAutoRepeatCount, QOverload<int>::of(&QSpinBox::valueChanged),
            this, [this]() { updateAutoCycleUi(); });
    connect(ui->inputAutoSequence, &QLineEdit::textChanged,
            this, [this]() { updateAutoCycleUi(); });
    connect(autoCycleTimer, &QTimer::timeout,
            this, &MainWindow::executeAutoCycleStep);
    connect(channelGroup, QOverload<int>::of(&QButtonGroup::idClicked),
            this, &MainWindow::selectChannel);

    connect(serialScanner, &SerialScanner::portsListChanged,
            this, &MainWindow::updatePortsState);
    connect(serialScanner, &SerialScanner::connectionStateChanged,
            this, &MainWindow::updateConnectionState);
    // Все ответы платы попадают в лог, а затем при необходимости разбираются на полезные данные.
    connect(serialScanner, &SerialScanner::lineReceived,
            this, [this](const QString &line) {
                appendLogLine("RX", line);
                handleIncomingLine(line);
            });
    connect(serialScanner, &SerialScanner::commandSent,
            this, [this](const QString &line) {
                appendLogLine("TX", line);
            });
    connect(serialScanner, &SerialScanner::errorTextChanged,
            this, [this](const QString &errorText) {
                appendLogLine("ERR", errorText);
            });
}

void MainWindow::initializeChannelPositions()
{
    // Для каждого канала храним абсолютную координату, куда нужно перейти.
    channelPositions = QVector<QPointF>(13, QPointF(0.0, 0.0));
    refreshChannelLabels();
}

void MainWindow::updateConnectionState(bool connected, const QString &message)
{
    if (connected) {
        currentPort = message;
        ui->labelStatus->setText(QStringLiteral("Статус: подключено (%1)").arg(message));
        ui->btnConnect->setText("Отключиться");
        ui->comboPorts->setEnabled(false);
        ui->btnRefresh->setEnabled(false);
        ui->labelDetails->setText(QStringLiteral(
            "Соединение открыто. Порт: %1\n"
            "Скорость: 115200, формат: 8N1.\n"
            "Теперь можно читать ответы платы, отправлять команды и работать с каналами.")
            .arg(message));
        appendLogLine("SYS", QStringLiteral("Подключение открыто: %1").arg(message));
        // Сразу запрашиваем сведения о прошивке и текущих координатах, чтобы заполнить интерфейс.
        serialScanner->sendCommands({ "M115", "M114" });
        updateAutoCycleUi();
        return;
    }

    if (autoCycleActive) {
        stopAutoCycle(true);
    }

    currentPort.clear();
    ui->labelStatus->setText("Статус: отключено");
    ui->btnConnect->setText("Подключиться");
    ui->comboPorts->setEnabled(true);
    ui->btnRefresh->setEnabled(true);
    ui->labelDetails->setText(message.isEmpty()
                              ? QStringLiteral("Подключение закрыто. Выберите порт и подключитесь снова.")
                              : QStringLiteral("Подключение закрыто: %1").arg(message));
    appendLogLine("SYS", message.isEmpty() ? QStringLiteral("Соединение закрыто")
                                           : QStringLiteral("Соединение закрыто: %1").arg(message));
    updateAutoCycleUi();
}

void MainWindow::updatePortsState(const QStringList &ports)
{
    ui->comboPorts->clear();

    if (ports.isEmpty()) {
        ui->comboPorts->setCurrentIndex(-1);
        ui->labelStatus->setText("Статус: порты не найдены");
        ui->labelDetails->setText("COM-порты не найдены. Проверьте кабель, питание платы и драйвер USB-UART.");
        return;
    }

    ui->comboPorts->addItems(ports);
    ui->comboPorts->setCurrentIndex(0);
    ui->labelStatus->setText(QStringLiteral("Статус: найдено портов %1").arg(ports.size()));
    ui->labelDetails->setText(QStringLiteral(
        "Найдено портов: %1\n"
        "Выберите нужную плату и нажмите 'Подключиться'.")
        .arg(ports.size()));
}

void MainWindow::appendLogLine(const QString &prefix, const QString &text)
{
    const QString timestamp = QDateTime::currentDateTime().toString("HH:mm:ss");
    ui->terminalLog->appendPlainText(QStringLiteral("[%1] %2  %3").arg(timestamp, prefix, text));
}

void MainWindow::sendManualMove(double deltaX, double deltaY)
{
    if (!serialScanner->isConnected()) {
        appendLogLine("ERR", "Для движения сначала подключитесь к плате.");
        return;
    }

    if (autoCycleActive) {
        stopAutoCycle(true);
    }

    const QString moveCommand = QStringLiteral("G0 X%1 Y%2 F3000")
        .arg(deltaX, 0, 'f', 1)
        .arg(deltaY, 0, 'f', 1);

    // Двигаемся в относительном режиме и затем обязательно возвращаем абсолютный,
    // чтобы остальные команды продолжали работать предсказуемо.
    if (!serialScanner->sendCommands({ "G91", moveCommand, "G90" })) {
        appendLogLine("ERR", serialScanner->lastError());
        return;
    }

    if (hasKnownPosition) {
        setCurrentPosition(currentPosition.x() + deltaX, currentPosition.y() + deltaY, false);
    }
}

void MainWindow::applyChannelSelection(int channelIndex)
{
    if (channelIndex < 0 || channelIndex >= channelPositions.size()) {
        return;
    }

    currentChannelIndex = channelIndex;
    channelButtons[channelIndex]->setChecked(true);
    refreshChannelLabels();
}

QString MainWindow::channelTitle(int channelIndex) const
{
    return channelIndex == 0
        ? QStringLiteral("Эталонный канал")
        : QStringLiteral("Канал %1").arg(channelIndex + 1);
}

void MainWindow::setCurrentPosition(double x, double y, bool fromDevice)
{
    currentPosition = QPointF(x, y);
    hasKnownPosition = true;
    refreshChannelLabels();

    // Отмечаем, пришла ли позиция от контроллера или была обновлена локально после нашей команды.
    appendLogLine("POS", QStringLiteral("Текущая позиция %1 (%2)")
                  .arg(positionText(currentPosition),
                       fromDevice ? QStringLiteral("считано с платы")
                                  : QStringLiteral("локально обновлено")));
}

QString MainWindow::positionText(const QPointF &position) const
{
    return QStringLiteral("X=%1, Y=%2")
        .arg(position.x(), 0, 'f', 1)
        .arg(position.y(), 0, 'f', 1);
}

void MainWindow::refreshChannelLabels()
{
    for (int index = 0; index < channelButtons.size(); ++index) {
        const QString shortTitle = index == 0 ? QStringLiteral("Эталон")
                                              : QStringLiteral("Канал %1").arg(index + 1);
        channelButtons[index]->setText(QStringLiteral("%1\n%2")
                                       .arg(shortTitle, positionText(channelPositions[index])));
        channelButtons[index]->setToolTip(QStringLiteral("%1\n%2")
                                          .arg(channelTitle(index), positionText(channelPositions[index])));
    }

    ui->labelSelectedChannel->setText(QStringLiteral("Выбран: %1").arg(channelTitle(currentChannelIndex)));
    ui->labelCurrentPosition->setText(
        hasKnownPosition
            ? QStringLiteral("Текущая позиция позиционера:\n%1").arg(positionText(currentPosition))
            : QStringLiteral("Текущая позиция позиционера:\nне считана. Нажмите 'Считать текущую позицию (M114)'."));
    ui->labelChannelPosition->setText(
        QStringLiteral("Сохранённая позиция для %1:\n%2")
            .arg(channelTitle(currentChannelIndex), positionText(channelPositions[currentChannelIndex])));
}

void MainWindow::requestCurrentPosition()
{
    if (!serialScanner->sendCommand("M114")) {
        appendLogLine("ERR", serialScanner->lastError());
    }
}

bool MainWindow::moveToChannel(int channelIndex, const QString &successMessage)
{
    if (channelIndex < 0 || channelIndex >= channelPositions.size()) {
        appendLogLine("ERR", "Неверный номер канала для перехода.");
        return false;
    }

    const QPointF target = channelPositions[channelIndex];
    const QString command = QStringLiteral("G0 X%1 Y%2 F3000")
        .arg(target.x(), 0, 'f', 1)
        .arg(target.y(), 0, 'f', 1);

    // Переходы по каналам всегда выполняются в абсолютных координатах.
    if (!serialScanner->sendCommands({ "G90", command })) {
        appendLogLine("ERR", serialScanner->lastError());
        return false;
    }

    setCurrentPosition(target.x(), target.y(), false);
    appendLogLine("SYS", successMessage);
    return true;
}

bool MainWindow::parseAutoCycleSequence(QVector<int> *sequence, QString *errorText) const
{
    if (sequence == nullptr) {
        return false;
    }

    sequence->clear();

    QString rawSequence = ui->inputAutoSequence->text().trimmed();
    if (rawSequence.isEmpty()) {
        if (errorText != nullptr) {
            *errorText = "Введите последовательность каналов, например: 1 2 3 2 4 5 3.";
        }
        return false;
    }

    rawSequence.replace(QRegularExpression(QStringLiteral("[,;\\n\\t]+")), QStringLiteral(" "));
    const QStringList tokens = rawSequence.split(QRegularExpression(QStringLiteral("\\s+")),
                                                 Qt::SkipEmptyParts);

    for (const QString &token : tokens) {
        bool ok = false;
        const int channelNumber = token.toInt(&ok);

        if (!ok || channelNumber < 1 || channelNumber > channelPositions.size()) {
            if (errorText != nullptr) {
                *errorText = QStringLiteral(
                    "Маршрут должен содержать только номера каналов от 1 до %1. Ошибка в значении: \"%2\".")
                    .arg(channelPositions.size())
                    .arg(token);
            }
            return false;
        }

        sequence->append(channelNumber - 1);
    }

    if (sequence->isEmpty()) {
        if (errorText != nullptr) {
            *errorText = "Последовательность автоцикла не должна быть пустой.";
        }
        return false;
    }

    return true;
}

QString MainWindow::autoCycleSequenceText(const QVector<int> &sequence) const
{
    if (sequence.isEmpty()) {
        return QStringLiteral("не задан");
    }

    QStringList channelNumbers;
    channelNumbers.reserve(sequence.size());

    for (const int channelIndex : sequence) {
        channelNumbers.append(QString::number(channelIndex + 1));
    }

    return channelNumbers.join(QStringLiteral(" "));
}

void MainWindow::updateAutoCycleUi()
{
    const int repeatLimit = ui->spinAutoRepeatCount->value();
    const QString repeatText = repeatLimit == 0
        ? QStringLiteral("без ограничения")
        : QStringLiteral("%1").arg(repeatLimit);

    ui->btnStartAutoCycle->setEnabled(!autoCycleActive && serialScanner->isConnected());
    ui->btnStopAutoCycle->setEnabled(autoCycleActive);
    ui->spinAutoDelayMs->setEnabled(!autoCycleActive);
    ui->spinAutoRepeatCount->setEnabled(!autoCycleActive);
    ui->inputAutoSequence->setEnabled(!autoCycleActive);

    ui->btnConnect->setEnabled(!autoCycleActive);
    ui->btnMoveLeft->setEnabled(!autoCycleActive);
    ui->btnMoveRight->setEnabled(!autoCycleActive);
    ui->btnMoveUp->setEnabled(!autoCycleActive);
    ui->btnMoveDown->setEnabled(!autoCycleActive);
    ui->btnHome->setEnabled(!autoCycleActive);
    ui->btnRequestPosition->setEnabled(!autoCycleActive);
    ui->btnCapturePosition->setEnabled(!autoCycleActive);
    ui->btnExecuteChannel->setEnabled(!autoCycleActive);

    for (QPushButton *button : channelButtons) {
        button->setEnabled(!autoCycleActive);
    }

    if (autoCycleActive) {
        const int nextChannelIndex = autoCycleSequence.isEmpty()
            ? currentChannelIndex
            : autoCycleSequence.value(autoCycleSequencePosition, currentChannelIndex);
        ui->labelAutoCycleState->setText(QStringLiteral(
            "Автоцикл выполняется.\n"
            "Следующий канал: %1\n"
            "Маршрут: %2\n"
            "Завершено кругов: %3 / %4\n"
            "Пауза между переходами: %5 мс")
            .arg(channelTitle(nextChannelIndex),
                 autoCycleSequenceText(autoCycleSequence),
                 QString::number(autoCycleCompletedLoops),
                 repeatText,
                 QString::number(ui->spinAutoDelayMs->value())));
        return;
    }

    ui->labelAutoCycleState->setText(QStringLiteral(
        "Автоцикл остановлен.\n"
        "Маршрут задаётся номерами каналов 1-13, повторы разрешены.\n"
        "Настройка: %1 кругов, пауза %2 мс, маршрут: %3.")
        .arg(repeatText,
             QString::number(ui->spinAutoDelayMs->value()),
             ui->inputAutoSequence->text().trimmed()));
}

void MainWindow::stopAutoCycle(bool writeLog)
{
    if (!autoCycleActive && !autoCycleTimer->isActive()) {
        updateAutoCycleUi();
        return;
    }

    autoCycleTimer->stop();
    autoCycleActive = false;

    if (writeLog) {
        appendLogLine("SYS", "Автоцикл остановлен.");
    }

    updateAutoCycleUi();
}

void MainWindow::handleIncomingLine(const QString &line)
{
    // Ожидаем типичный ответ M114 вида "X:10.0 Y:20.0 ..."; остальное просто оставляем в логе.
    static const QRegularExpression positionRegex(
        QStringLiteral("X:([+-]?\\d+(?:\\.\\d+)?)\\s+Y:([+-]?\\d+(?:\\.\\d+)?)"));

    const QRegularExpressionMatch match = positionRegex.match(line);
    if (!match.hasMatch()) {
        return;
    }

    setCurrentPosition(match.captured(1).toDouble(), match.captured(2).toDouble(), true);
}

void MainWindow::refreshPortOnClick()
{
    if (serialScanner->isConnected()) {
        serialScanner->closePort();
    }

    serialScanner->refreshPorts();
}

void MainWindow::connectPortOnClick()
{
    if (serialScanner->isConnected()) {
        serialScanner->closePort();
        return;
    }

    const int selectedIndex = ui->comboPorts->currentIndex();
    if (!serialScanner->openPortByIndex(selectedIndex)) {
        ui->labelStatus->setText("Статус: ошибка подключения");
        ui->labelDetails->setText(QStringLiteral("Не удалось открыть порт.\nПричина: %1")
                                  .arg(serialScanner->lastError()));
    }
}

void MainWindow::sendGcodeOnClick()
{
    const QString command = ui->inputGcode->text().trimmed();
    if (command.isEmpty()) {
        return;
    }

    if (!serialScanner->sendCommand(command)) {
        appendLogLine("ERR", serialScanner->lastError());
        return;
    }

    ui->inputGcode->clear();
}

void MainWindow::selectChannel(int channelId)
{
    applyChannelSelection(channelId);
}

void MainWindow::captureCurrentPositionForChannel()
{
    if (autoCycleActive) {
        appendLogLine("ERR", "Остановите автоцикл перед записью позиции канала.");
        return;
    }

    if (!hasKnownPosition) {
        appendLogLine("ERR", "Сначала считайте позицию платы через M114 или доведите позиционер после калибровки.");
        return;
    }

    // Запоминаем текущую абсолютную позицию как координату выбранного канала.
    channelPositions[currentChannelIndex] = currentPosition;
    refreshChannelLabels();
    appendLogLine("SYS", QStringLiteral("Для %1 сохранена позиция %2")
                  .arg(channelTitle(currentChannelIndex), positionText(currentPosition)));
}

void MainWindow::executeCurrentChannel()
{
    if (!serialScanner->isConnected()) {
        appendLogLine("ERR", "Для перехода по каналу сначала подключитесь к плате.");
        return;
    }

    if (autoCycleActive) {
        appendLogLine("ERR", "Остановите автоцикл перед ручным переходом по каналу.");
        return;
    }

    moveToChannel(currentChannelIndex,
                  QStringLiteral("Выполнен переход к %1").arg(channelTitle(currentChannelIndex)));
}

void MainWindow::startAutoCycle()
{
    if (!serialScanner->isConnected()) {
        appendLogLine("ERR", "Для автоцикла сначала подключитесь к плате.");
        updateAutoCycleUi();
        return;
    }

    if (channelPositions.isEmpty()) {
        appendLogLine("ERR", "Нет сохранённых положений для автоцикла.");
        return;
    }

    QVector<int> sequence;
    QString sequenceError;
    if (!parseAutoCycleSequence(&sequence, &sequenceError)) {
        appendLogLine("ERR", sequenceError);
        updateAutoCycleUi();
        return;
    }

    autoCycleSequence = sequence;
    autoCycleActive = true;
    autoCycleSequencePosition = 0;
    autoCycleCompletedLoops = 0;
    autoCycleTimer->setInterval(ui->spinAutoDelayMs->value());

    appendLogLine("SYS", QStringLiteral("Автоцикл запущен. Маршрут: %1.")
                  .arg(autoCycleSequenceText(autoCycleSequence)));
    updateAutoCycleUi();
    executeAutoCycleStep();
}

void MainWindow::stopAutoCycleOnClick()
{
    stopAutoCycle(true);
}

void MainWindow::executeAutoCycleStep()
{
    if (!autoCycleActive) {
        autoCycleTimer->stop();
        updateAutoCycleUi();
        return;
    }

    if (!serialScanner->isConnected()) {
        stopAutoCycle(true);
        appendLogLine("ERR", "Автоцикл остановлен: порт отключён.");
        return;
    }

    if (autoCycleSequence.isEmpty()) {
        stopAutoCycle(true);
        appendLogLine("ERR", "Автоцикл остановлен: последовательность каналов пустая.");
        return;
    }

    const int targetIndex = autoCycleSequence.value(autoCycleSequencePosition, currentChannelIndex);
    applyChannelSelection(targetIndex);

    if (!moveToChannel(targetIndex,
                       QStringLiteral("Автоцикл: переход к %1")
                           .arg(channelTitle(targetIndex)))) {
        stopAutoCycle(true);
        return;
    }

    ++autoCycleSequencePosition;
    if (autoCycleSequencePosition >= autoCycleSequence.size()) {
        autoCycleSequencePosition = 0;
        ++autoCycleCompletedLoops;
    }

    const int repeatLimit = ui->spinAutoRepeatCount->value();
    if (repeatLimit > 0 && autoCycleCompletedLoops >= repeatLimit) {
        stopAutoCycle(false);
        appendLogLine("SYS", QStringLiteral("Автоцикл завершён: выполнено кругов %1.")
                      .arg(autoCycleCompletedLoops));
        return;
    }

    if (!autoCycleTimer->isActive()) {
        autoCycleTimer->start();
    }

    updateAutoCycleUi();
}
