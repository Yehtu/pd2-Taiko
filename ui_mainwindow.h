/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *PlayButton;
    QPushButton *ExitButton;
    QPushButton *informButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(805, 505);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 800, 500));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/menu.jpg")));
        PlayButton = new QPushButton(centralWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));
        PlayButton->setGeometry(QRect(380, 365, 100, 35));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        PlayButton->setFont(font);
        PlayButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(380, 455, 100, 35));
        ExitButton->setFont(font);
        ExitButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        informButton = new QPushButton(centralWidget);
        informButton->setObjectName(QStringLiteral("informButton"));
        informButton->setGeometry(QRect(360, 410, 140, 35));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        informButton->setFont(font1);
        informButton->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 805, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QString());
        PlayButton->setText(QApplication::translate("MainWindow", "Start", 0));
        ExitButton->setText(QApplication::translate("MainWindow", "exit", 0));
        informButton->setText(QApplication::translate("MainWindow", "how to play", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
