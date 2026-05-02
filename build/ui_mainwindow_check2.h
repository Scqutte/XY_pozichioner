/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_CHECK2_H
#define UI_MAINWINDOW_CHECK2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QFrame *headerCard;
    QHBoxLayout *headerLayout;
    QVBoxLayout *headerTextLayout;
    QLabel *titleLabel;
    QLabel *topLabel;
    QLabel *labelStatus;
    QGridLayout *contentLayout;
    QFrame *panelConnection;
    QVBoxLayout *connectionLayout;
    QLabel *connectionTitle;
    QHBoxLayout *portRowLayout;
    QComboBox *comboPorts;
    QPushButton *btnRefresh;
    QPushButton *btnConnect;
    QLabel *labelDetails;
    QFrame *panelControls;
    QVBoxLayout *controlsLayout;
    QLabel *controlsTitle;
    QHBoxLayout *stepRowLayout;
    QLabel *stepLabel;
    QSpacerItem *stepSpacer;
    QDoubleSpinBox *spinMoveStep;
    QGridLayout *moveGridLayout;
    QPushButton *btnMoveUp;
    QPushButton *btnMoveLeft;
    QLabel *centerLabel;
    QPushButton *btnMoveRight;
    QPushButton *btnMoveDown;
    QPushButton *btnHome;
    QPushButton *btnStop;
    QSpacerItem *leftSpacer;
    QFrame *panelGcode;
    QVBoxLayout *gcodeLayout;
    QLabel *gcodeTitle;
    QHBoxLayout *gcodeRowLayout;
    QLineEdit *inputGcode;
    QPushButton *btnSendGcode;
    QPushButton *btnClearLog;
    QFrame *panelLog;
    QVBoxLayout *logLayout;
    QLabel *logTitle;
    QPlainTextEdit *terminalLog;
    QSpacerItem *rightTopSpacer;
    QSpacerItem *rightSpacer;
    QFrame *panelChannels;
    QVBoxLayout *channelsLayout;
    QLabel *channelsTitle;
    QLabel *channelsHint;
    QGridLayout *channelsGridLayout;
    QPushButton *btnChannel1;
    QPushButton *btnChannel2;
    QPushButton *btnChannel3;
    QPushButton *btnChannel4;
    QPushButton *btnChannel5;
    QPushButton *btnChannel6;
    QPushButton *btnChannel7;
    QPushButton *btnChannel8;
    QPushButton *btnChannel9;
    QPushButton *btnChannel10;
    QPushButton *btnChannel11;
    QPushButton *btnChannel12;
    QPushButton *btnChannel13;
    QLabel *labelSelectedChannel;
    QLabel *labelCurrentPosition;
    QLabel *labelChannelPosition;
    QHBoxLayout *channelActionsLayout;
    QPushButton *btnRequestPosition;
    QPushButton *btnCapturePosition;
    QPushButton *btnExecuteChannel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1440, 920);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setSpacing(18);
        rootLayout->setObjectName(QString::fromUtf8("rootLayout"));
        rootLayout->setContentsMargins(24, 20, 24, 20);
        headerCard = new QFrame(centralwidget);
        headerCard->setObjectName(QString::fromUtf8("headerCard"));
        headerCard->setFrameShape(QFrame::StyledPanel);
        headerLayout = new QHBoxLayout(headerCard);
        headerLayout->setSpacing(18);
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        headerLayout->setContentsMargins(24, 18, 24, 18);
        headerTextLayout = new QVBoxLayout();
        headerTextLayout->setSpacing(4);
        headerTextLayout->setObjectName(QString::fromUtf8("headerTextLayout"));
        titleLabel = new QLabel(headerCard);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        headerTextLayout->addWidget(titleLabel);

        topLabel = new QLabel(headerCard);
        topLabel->setObjectName(QString::fromUtf8("topLabel"));
        topLabel->setWordWrap(true);

        headerTextLayout->addWidget(topLabel);


        headerLayout->addLayout(headerTextLayout);

        labelStatus = new QLabel(headerCard);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setMinimumSize(QSize(220, 0));
        labelStatus->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(labelStatus);


        rootLayout->addWidget(headerCard);

        contentLayout = new QGridLayout();
        contentLayout->setObjectName(QString::fromUtf8("contentLayout"));
        contentLayout->setHorizontalSpacing(20);
        contentLayout->setVerticalSpacing(18);
        panelConnection = new QFrame(centralwidget);
        panelConnection->setObjectName(QString::fromUtf8("panelConnection"));
        panelConnection->setFrameShape(QFrame::StyledPanel);
        connectionLayout = new QVBoxLayout(panelConnection);
        connectionLayout->setSpacing(14);
        connectionLayout->setObjectName(QString::fromUtf8("connectionLayout"));
        connectionLayout->setContentsMargins(20, 20, 20, 20);
        connectionTitle = new QLabel(panelConnection);
        connectionTitle->setObjectName(QString::fromUtf8("connectionTitle"));

        connectionLayout->addWidget(connectionTitle);

        portRowLayout = new QHBoxLayout();
        portRowLayout->setSpacing(12);
        portRowLayout->setObjectName(QString::fromUtf8("portRowLayout"));
        comboPorts = new QComboBox(panelConnection);
        comboPorts->setObjectName(QString::fromUtf8("comboPorts"));
        comboPorts->setMinimumSize(QSize(0, 42));

        portRowLayout->addWidget(comboPorts);

        btnRefresh = new QPushButton(panelConnection);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setMinimumSize(QSize(0, 40));

        portRowLayout->addWidget(btnRefresh);

        btnConnect = new QPushButton(panelConnection);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setMinimumSize(QSize(0, 44));

        portRowLayout->addWidget(btnConnect);


        connectionLayout->addLayout(portRowLayout);

        labelDetails = new QLabel(panelConnection);
        labelDetails->setObjectName(QString::fromUtf8("labelDetails"));
        labelDetails->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        labelDetails->setWordWrap(true);

        connectionLayout->addWidget(labelDetails);


        contentLayout->addWidget(panelConnection, 0, 0, 1, 1);

        panelControls = new QFrame(centralwidget);
        panelControls->setObjectName(QString::fromUtf8("panelControls"));
        panelControls->setFrameShape(QFrame::StyledPanel);
        controlsLayout = new QVBoxLayout(panelControls);
        controlsLayout->setSpacing(14);
        controlsLayout->setObjectName(QString::fromUtf8("controlsLayout"));
        controlsLayout->setContentsMargins(20, 20, 20, 20);
        controlsTitle = new QLabel(panelControls);
        controlsTitle->setObjectName(QString::fromUtf8("controlsTitle"));

        controlsLayout->addWidget(controlsTitle);

        stepRowLayout = new QHBoxLayout();
        stepRowLayout->setObjectName(QString::fromUtf8("stepRowLayout"));
        stepLabel = new QLabel(panelControls);
        stepLabel->setObjectName(QString::fromUtf8("stepLabel"));

        stepRowLayout->addWidget(stepLabel);

        stepSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        stepRowLayout->addItem(stepSpacer);

        spinMoveStep = new QDoubleSpinBox(panelControls);
        spinMoveStep->setObjectName(QString::fromUtf8("spinMoveStep"));
        spinMoveStep->setMinimumSize(QSize(130, 38));
        spinMoveStep->setDecimals(1);
        spinMoveStep->setMinimum(0.100000000000000);
        spinMoveStep->setMaximum(1000.000000000000000);
        spinMoveStep->setSingleStep(1.000000000000000);
        spinMoveStep->setValue(10.000000000000000);

        stepRowLayout->addWidget(spinMoveStep);


        controlsLayout->addLayout(stepRowLayout);

        moveGridLayout = new QGridLayout();
        moveGridLayout->setObjectName(QString::fromUtf8("moveGridLayout"));
        moveGridLayout->setHorizontalSpacing(12);
        moveGridLayout->setVerticalSpacing(12);
        btnMoveUp = new QPushButton(panelControls);
        btnMoveUp->setObjectName(QString::fromUtf8("btnMoveUp"));
        btnMoveUp->setMinimumSize(QSize(92, 48));

        moveGridLayout->addWidget(btnMoveUp, 0, 1, 1, 1);

        btnMoveLeft = new QPushButton(panelControls);
        btnMoveLeft->setObjectName(QString::fromUtf8("btnMoveLeft"));
        btnMoveLeft->setMinimumSize(QSize(92, 48));

        moveGridLayout->addWidget(btnMoveLeft, 1, 0, 1, 1);

        centerLabel = new QLabel(panelControls);
        centerLabel->setObjectName(QString::fromUtf8("centerLabel"));
        centerLabel->setMinimumSize(QSize(92, 48));
        centerLabel->setAlignment(Qt::AlignCenter);

        moveGridLayout->addWidget(centerLabel, 1, 1, 1, 1);

        btnMoveRight = new QPushButton(panelControls);
        btnMoveRight->setObjectName(QString::fromUtf8("btnMoveRight"));
        btnMoveRight->setMinimumSize(QSize(92, 48));

        moveGridLayout->addWidget(btnMoveRight, 1, 2, 1, 1);

        btnMoveDown = new QPushButton(panelControls);
        btnMoveDown->setObjectName(QString::fromUtf8("btnMoveDown"));
        btnMoveDown->setMinimumSize(QSize(92, 48));

        moveGridLayout->addWidget(btnMoveDown, 2, 1, 1, 1);


        controlsLayout->addLayout(moveGridLayout);

        btnHome = new QPushButton(panelControls);
        btnHome->setObjectName(QString::fromUtf8("btnHome"));
        btnHome->setMinimumSize(QSize(0, 40));

        controlsLayout->addWidget(btnHome);

        btnStop = new QPushButton(panelControls);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setMinimumSize(QSize(0, 40));

        controlsLayout->addWidget(btnStop);


        contentLayout->addWidget(panelControls, 1, 0, 1, 1);

        leftSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        contentLayout->addItem(leftSpacer, 2, 0, 1, 1);

        panelGcode = new QFrame(centralwidget);
        panelGcode->setObjectName(QString::fromUtf8("panelGcode"));
        panelGcode->setFrameShape(QFrame::StyledPanel);
        gcodeLayout = new QVBoxLayout(panelGcode);
        gcodeLayout->setSpacing(14);
        gcodeLayout->setObjectName(QString::fromUtf8("gcodeLayout"));
        gcodeLayout->setContentsMargins(20, 20, 20, 20);
        gcodeTitle = new QLabel(panelGcode);
        gcodeTitle->setObjectName(QString::fromUtf8("gcodeTitle"));

        gcodeLayout->addWidget(gcodeTitle);

        gcodeRowLayout = new QHBoxLayout();
        gcodeRowLayout->setSpacing(12);
        gcodeRowLayout->setObjectName(QString::fromUtf8("gcodeRowLayout"));
        inputGcode = new QLineEdit(panelGcode);
        inputGcode->setObjectName(QString::fromUtf8("inputGcode"));
        inputGcode->setMinimumSize(QSize(0, 42));

        gcodeRowLayout->addWidget(inputGcode);

        btnSendGcode = new QPushButton(panelGcode);
        btnSendGcode->setObjectName(QString::fromUtf8("btnSendGcode"));
        btnSendGcode->setMinimumSize(QSize(0, 40));

        gcodeRowLayout->addWidget(btnSendGcode);

        btnClearLog = new QPushButton(panelGcode);
        btnClearLog->setObjectName(QString::fromUtf8("btnClearLog"));
        btnClearLog->setMinimumSize(QSize(0, 40));

        gcodeRowLayout->addWidget(btnClearLog);


        gcodeLayout->addLayout(gcodeRowLayout);


        contentLayout->addWidget(panelGcode, 3, 0, 1, 1);

        panelLog = new QFrame(centralwidget);
        panelLog->setObjectName(QString::fromUtf8("panelLog"));
        panelLog->setFrameShape(QFrame::StyledPanel);
        logLayout = new QVBoxLayout(panelLog);
        logLayout->setSpacing(14);
        logLayout->setObjectName(QString::fromUtf8("logLayout"));
        logLayout->setContentsMargins(20, 20, 20, 20);
        logTitle = new QLabel(panelLog);
        logTitle->setObjectName(QString::fromUtf8("logTitle"));

        logLayout->addWidget(logTitle);

        terminalLog = new QPlainTextEdit(panelLog);
        terminalLog->setObjectName(QString::fromUtf8("terminalLog"));
        terminalLog->setMinimumSize(QSize(0, 220));
        terminalLog->setMaximumSize(QSize(16777215, 280));
        terminalLog->setReadOnly(true);

        logLayout->addWidget(terminalLog);


        contentLayout->addWidget(panelLog, 0, 1, 1, 1);

        rightTopSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        contentLayout->addItem(rightTopSpacer, 1, 1, 1, 1);

        rightSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        contentLayout->addItem(rightSpacer, 2, 1, 1, 1);

        panelChannels = new QFrame(centralwidget);
        panelChannels->setObjectName(QString::fromUtf8("panelChannels"));
        panelChannels->setFrameShape(QFrame::StyledPanel);
        channelsLayout = new QVBoxLayout(panelChannels);
        channelsLayout->setSpacing(14);
        channelsLayout->setObjectName(QString::fromUtf8("channelsLayout"));
        channelsLayout->setContentsMargins(20, 20, 20, 20);
        channelsTitle = new QLabel(panelChannels);
        channelsTitle->setObjectName(QString::fromUtf8("channelsTitle"));

        channelsLayout->addWidget(channelsTitle);

        channelsHint = new QLabel(panelChannels);
        channelsHint->setObjectName(QString::fromUtf8("channelsHint"));
        channelsHint->setWordWrap(true);

        channelsLayout->addWidget(channelsHint);

        channelsGridLayout = new QGridLayout();
        channelsGridLayout->setObjectName(QString::fromUtf8("channelsGridLayout"));
        channelsGridLayout->setHorizontalSpacing(10);
        channelsGridLayout->setVerticalSpacing(10);
        btnChannel1 = new QPushButton(panelChannels);
        btnChannel1->setObjectName(QString::fromUtf8("btnChannel1"));
        btnChannel1->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel1, 0, 0, 1, 1);

        btnChannel2 = new QPushButton(panelChannels);
        btnChannel2->setObjectName(QString::fromUtf8("btnChannel2"));
        btnChannel2->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel2, 0, 1, 1, 1);

        btnChannel3 = new QPushButton(panelChannels);
        btnChannel3->setObjectName(QString::fromUtf8("btnChannel3"));
        btnChannel3->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel3, 0, 2, 1, 1);

        btnChannel4 = new QPushButton(panelChannels);
        btnChannel4->setObjectName(QString::fromUtf8("btnChannel4"));
        btnChannel4->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel4, 0, 3, 1, 1);

        btnChannel5 = new QPushButton(panelChannels);
        btnChannel5->setObjectName(QString::fromUtf8("btnChannel5"));
        btnChannel5->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel5, 0, 4, 1, 1);

        btnChannel6 = new QPushButton(panelChannels);
        btnChannel6->setObjectName(QString::fromUtf8("btnChannel6"));
        btnChannel6->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel6, 1, 0, 1, 1);

        btnChannel7 = new QPushButton(panelChannels);
        btnChannel7->setObjectName(QString::fromUtf8("btnChannel7"));
        btnChannel7->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel7, 1, 1, 1, 1);

        btnChannel8 = new QPushButton(panelChannels);
        btnChannel8->setObjectName(QString::fromUtf8("btnChannel8"));
        btnChannel8->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel8, 1, 2, 1, 1);

        btnChannel9 = new QPushButton(panelChannels);
        btnChannel9->setObjectName(QString::fromUtf8("btnChannel9"));
        btnChannel9->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel9, 1, 3, 1, 1);

        btnChannel10 = new QPushButton(panelChannels);
        btnChannel10->setObjectName(QString::fromUtf8("btnChannel10"));
        btnChannel10->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel10, 1, 4, 1, 1);

        btnChannel11 = new QPushButton(panelChannels);
        btnChannel11->setObjectName(QString::fromUtf8("btnChannel11"));
        btnChannel11->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel11, 2, 0, 1, 1);

        btnChannel12 = new QPushButton(panelChannels);
        btnChannel12->setObjectName(QString::fromUtf8("btnChannel12"));
        btnChannel12->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel12, 2, 1, 1, 1);

        btnChannel13 = new QPushButton(panelChannels);
        btnChannel13->setObjectName(QString::fromUtf8("btnChannel13"));
        btnChannel13->setCheckable(true);

        channelsGridLayout->addWidget(btnChannel13, 2, 2, 1, 1);


        channelsLayout->addLayout(channelsGridLayout);

        labelSelectedChannel = new QLabel(panelChannels);
        labelSelectedChannel->setObjectName(QString::fromUtf8("labelSelectedChannel"));

        channelsLayout->addWidget(labelSelectedChannel);

        labelCurrentPosition = new QLabel(panelChannels);
        labelCurrentPosition->setObjectName(QString::fromUtf8("labelCurrentPosition"));
        labelCurrentPosition->setWordWrap(true);

        channelsLayout->addWidget(labelCurrentPosition);

        labelChannelPosition = new QLabel(panelChannels);
        labelChannelPosition->setObjectName(QString::fromUtf8("labelChannelPosition"));
        labelChannelPosition->setWordWrap(true);

        channelsLayout->addWidget(labelChannelPosition);

        channelActionsLayout = new QHBoxLayout();
        channelActionsLayout->setSpacing(12);
        channelActionsLayout->setObjectName(QString::fromUtf8("channelActionsLayout"));
        btnRequestPosition = new QPushButton(panelChannels);
        btnRequestPosition->setObjectName(QString::fromUtf8("btnRequestPosition"));
        btnRequestPosition->setMinimumSize(QSize(0, 40));

        channelActionsLayout->addWidget(btnRequestPosition);

        btnCapturePosition = new QPushButton(panelChannels);
        btnCapturePosition->setObjectName(QString::fromUtf8("btnCapturePosition"));
        btnCapturePosition->setMinimumSize(QSize(0, 40));

        channelActionsLayout->addWidget(btnCapturePosition);

        btnExecuteChannel = new QPushButton(panelChannels);
        btnExecuteChannel->setObjectName(QString::fromUtf8("btnExecuteChannel"));
        btnExecuteChannel->setMinimumSize(QSize(0, 42));

        channelActionsLayout->addWidget(btnExecuteChannel);


        channelsLayout->addLayout(channelActionsLayout);


        contentLayout->addWidget(panelChannels, 3, 1, 1, 1);


        rootLayout->addLayout(contentLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "XY Pozicioner", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\273\320\260\321\202\320\276\320\271 3D-\320\277\321\200\320\270\320\275\321\202\320\265\321\200\320\260", nullptr));
        topLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\320\273\320\265\321\200\321\203, \320\266\321\203\321\200\320\275\320\260\320\273 \320\276\321\202\320\262\320\265\321\202\320\276\320\262 \320\277\320\273\320\260\321\202\321\213, \320\276\321\202\320\277\321\200\320\260\320\262\320\272\320\260 G-code, \321\200\321\203\321\207\320\275\320\276\320\265 \320\264\320\262\320\270\320\266\320\265\320\275\320\270\320\265 \320\277\320\276 X/Y \320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\320\271 \320\262 13 \320\272\320\260\320\275\320\260\320\273\320\276\320\262.", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201: \320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\276", nullptr));
        connectionTitle->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\272 \320\277\320\273\320\260\321\202\320\265", nullptr));
        btnRefresh->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\276\321\200\321\202\321\213", nullptr));
        btnConnect->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        labelDetails->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\320\273\320\265 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \320\274\320\276\320\266\320\275\320\276 \321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\276\321\202\320\262\320\265\321\202\321\213 \320\277\320\273\320\260\321\202\321\213 \320\270 \320\276\321\202\320\277\321\200\320\260\320\262\320\273\321\217\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\213.", nullptr));
        controlsTitle->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\207\320\275\320\276\320\265 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", nullptr));
        stepLabel->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263, \320\274\320\274", nullptr));
        btnMoveUp->setText(QCoreApplication::translate("MainWindow", "Y+", nullptr));
        btnMoveLeft->setText(QCoreApplication::translate("MainWindow", "X-", nullptr));
        centerLabel->setText(QCoreApplication::translate("MainWindow", "XY", nullptr));
        btnMoveRight->setText(QCoreApplication::translate("MainWindow", "X+", nullptr));
        btnMoveDown->setText(QCoreApplication::translate("MainWindow", "Y-", nullptr));
        btnHome->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 / Home (G28)", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\320\260\321\200\320\270\320\271\320\275\320\260\321\217 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 (M112)", nullptr));
        gcodeTitle->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\272\320\260 G-code", nullptr));
        inputGcode->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: M114, G28, G0 X10 Y20 F3000", nullptr));
        btnSendGcode->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnClearLog->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\266\321\203\321\200\320\275\320\260\320\273", nullptr));
        logTitle->setText(QCoreApplication::translate("MainWindow", "\320\226\321\203\321\200\320\275\320\260\320\273 \320\276\320\261\320\274\320\265\320\275\320\260 \321\201 \320\277\320\273\320\260\321\202\320\276\320\271", nullptr));
        channelsTitle->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273\321\213 \320\277\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        channelsHint->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\260\320\275\320\260\320\273, \320\264\320\276\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\265\321\200 \320\264\320\276 \320\275\321\203\320\266\320\275\320\276\320\271 \321\202\320\276\321\207\320\272\320\270 \321\201\321\202\321\200\320\265\320\273\320\272\320\260\320\274\320\270 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 '\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 \320\272\320\260\320\275\320\260\320\273\320\260'. \320\224\320\273\321\217 \320\267\320\260\320\277\321\203\321\201\320\272\320\260 \320\272\320\260\320\275\320\260\320\273\320\260 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202\321\201\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\320\260\321\217 \320"
                        "\277\320\276\320\267\320\270\321\206\320\270\321\217 X/Y.", nullptr));
        btnChannel1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 1", nullptr));
        btnChannel2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 2", nullptr));
        btnChannel3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 3", nullptr));
        btnChannel4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 4", nullptr));
        btnChannel5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 5", nullptr));
        btnChannel6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 6", nullptr));
        btnChannel7->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 7", nullptr));
        btnChannel8->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 8", nullptr));
        btnChannel9->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 9", nullptr));
        btnChannel10->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 10", nullptr));
        btnChannel11->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 11", nullptr));
        btnChannel12->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 12", nullptr));
        btnChannel13->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 13", nullptr));
        labelSelectedChannel->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\320\275: \320\255\321\202\320\260\320\273\320\276\320\275\320\275\321\213\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
        labelCurrentPosition->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\203\321\211\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\320\276\320\275\320\265\321\200\320\260:\n"
"\320\275\320\265 \321\201\321\207\320\270\321\202\320\260\320\275\320\260. \320\235\320\260\320\266\320\274\320\270\321\202\320\265 '\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 (M114)'.", nullptr));
        labelChannelPosition->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\321\221\320\275\320\275\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217 \320\264\320\273\321\217 \320\255\321\202\320\260\320\273\320\276\320\275\320\275\320\276\320\263\320\276 \320\272\320\260\320\275\320\260\320\273\320\260:\n"
"X=0.0, Y=0.0", nullptr));
        btnRequestPosition->setText(QCoreApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\321\203\321\216 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 (M114)", nullptr));
        btnCapturePosition->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\277\320\276\320\267\320\270\321\206\320\270\321\216 \320\272\320\260\320\275\320\260\320\273\320\260", nullptr));
        btnExecuteChannel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\274\321\203 \320\272\320\260\320\275\320\260\320\273\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_CHECK2_H
