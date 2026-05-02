/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_lamp;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_4;
    QFormLayout *formLayout;
    QLabel *label;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_mainChanal;
    QPushButton *pushButton_secondlyChanel;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1052, 849);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_lamp = new QLabel(centralwidget);
        label_lamp->setObjectName(QString::fromUtf8("label_lamp"));

        verticalLayout->addWidget(label_lamp);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setEditable(true);

        horizontalLayout->addWidget(comboBox);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(7);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setAutoDefault(false);
        pushButton_stop->setFlat(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton_stop);

        pushButton_mainChanal = new QPushButton(centralwidget);
        pushButton_mainChanal->setObjectName(QString::fromUtf8("pushButton_mainChanal"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_mainChanal);

        pushButton_secondlyChanel = new QPushButton(centralwidget);
        pushButton_secondlyChanel->setObjectName(QString::fromUtf8("pushButton_secondlyChanel"));
        pushButton_secondlyChanel->setContextMenuPolicy(Qt::PreventContextMenu);

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_secondlyChanel);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);


        verticalLayout->addLayout(formLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1052, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_stop->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Pozicioner", nullptr));
        label_lamp->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        comboBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        pushButton_mainChanal->setText(QCoreApplication::translate("MainWindow", "main", nullptr));
        pushButton_secondlyChanel->setText(QCoreApplication::translate("MainWindow", "first", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\273\320\276\320\275\320\275\321\213\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\222\321\202\320\276\321\200\320\276\321\201\321\202\320\265\320\277\320\265\320\275\320\275\321\213\320\271 \320\272\320\260\320\275\320\260\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
