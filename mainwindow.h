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

    Ui::MainWindow *ui;
    QButtonGroup *channelGroup;
    QVector<QPushButton *> channelButtons;
    SerialScanner *serialScanner;
    QString currentPort;
    QVector<QPointF> channelPositions;
    int currentChannelIndex;
    QPointF currentPosition;
    bool hasKnownPosition;

private slots:
    void refreshPortOnClick();
    void connectPortOnClick();
    void sendGcodeOnClick();
    void selectChannel(int channelId);
    void captureCurrentPositionForChannel();
    void executeCurrentChannel();
};

#endif // MAINWINDOW_H
