#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QPointF>
#include <QVector>

#include "serialscanner.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QPushButton;
class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupStyles();
    void setupChannelButtons();
    void setupConnections();
    void initializeChannelPositions();
    void updateConnectionState(bool connected, const QString &message);
    void updatePortsState(const QStringList &ports);
    void appendLogLine(const QString &prefix, const QString &text);
    void sendManualMove(double deltaX, double deltaY);
    void applyChannelSelection(int channelIndex);
    QString channelTitle(int channelIndex) const;
    void setCurrentPosition(double x, double y, bool fromDevice);
    QString positionText(const QPointF &position) const;
    void refreshChannelLabels();
    void requestCurrentPosition();
    void handleIncomingLine(const QString &line);
    bool moveToChannel(int channelIndex, const QString &successMessage);
    bool parseAutoCycleSequence(QVector<int> *sequence, QString *errorText) const;
    QString autoCycleSequenceText(const QVector<int> &sequence) const;
    void updateAutoCycleUi();
    void stopAutoCycle(bool writeLog);

    Ui::MainWindow *ui;
    QButtonGroup *channelGroup;
    QVector<QPushButton *> channelButtons;
    SerialScanner *serialScanner;
    QTimer *autoCycleTimer;
    QString currentPort;
    QVector<QPointF> channelPositions;
    QVector<int> autoCycleSequence;
    int currentChannelIndex;
    int autoCycleSequencePosition;
    int autoCycleCompletedLoops;
    QPointF currentPosition;
    bool hasKnownPosition;
    bool autoCycleActive;

private slots:
    void refreshPortOnClick();
    void connectPortOnClick();
    void sendGcodeOnClick();
    void selectChannel(int channelId);
    void captureCurrentPositionForChannel();
    void executeCurrentChannel();
    void startAutoCycle();
    void stopAutoCycleOnClick();
    void executeAutoCycleStep();
};

#endif // MAINWINDOW_H
