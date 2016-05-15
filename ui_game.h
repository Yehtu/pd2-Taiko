/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QLCDNumber *LCDtime;
    QLCDNumber *LCDscore;
    QLabel *TIME;
    QLabel *SCORE;
    QLabel *red;
    QLabel *blue;
    QLabel *PressA;
    QLabel *PressL;
    QLabel *pause;
    QLabel *PressP;

    void setupUi(QWidget *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(800, 500);
        LCDtime = new QLCDNumber(game);
        LCDtime->setObjectName(QStringLiteral("LCDtime"));
        LCDtime->setGeometry(QRect(440, 370, 130, 90));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        LCDtime->setFont(font);
        LCDtime->setStyleSheet(QLatin1String("background-color: rgb(90, 90, 90);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(255, 0, 0);"));
        LCDtime->setDigitCount(3);
        LCDscore = new QLCDNumber(game);
        LCDscore->setObjectName(QStringLiteral("LCDscore"));
        LCDscore->setGeometry(QRect(620, 370, 130, 90));
        LCDscore->setFont(font);
        LCDscore->setFocusPolicy(Qt::NoFocus);
        LCDscore->setStyleSheet(QLatin1String("background-color: rgb(90, 90, 90);\n"
"font: 75 9pt \"Agency FB\";\n"
"color: rgb(85, 0, 255);"));
        LCDscore->setDigitCount(3);
        TIME = new QLabel(game);
        TIME->setObjectName(QStringLiteral("TIME"));
        TIME->setGeometry(QRect(435, 300, 151, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(36);
        font1.setBold(true);
        font1.setWeight(75);
        TIME->setFont(font1);
        SCORE = new QLabel(game);
        SCORE->setObjectName(QStringLiteral("SCORE"));
        SCORE->setGeometry(QRect(605, 300, 171, 61));
        SCORE->setFont(font1);
        red = new QLabel(game);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(20, 145, 50, 50));
        red->setPixmap(QPixmap(QString::fromUtf8(":/img/bred.png")));
        red->setScaledContents(true);
        blue = new QLabel(game);
        blue->setObjectName(QStringLiteral("blue"));
        blue->setGeometry(QRect(20, 195, 50, 50));
        blue->setPixmap(QPixmap(QString::fromUtf8(":/img/bblue.png")));
        blue->setScaledContents(true);
        PressA = new QLabel(game);
        PressA->setObjectName(QStringLiteral("PressA"));
        PressA->setGeometry(QRect(80, 150, 100, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        PressA->setFont(font2);
        PressL = new QLabel(game);
        PressL->setObjectName(QStringLiteral("PressL"));
        PressL->setGeometry(QRect(80, 200, 100, 40));
        PressL->setFont(font2);
        pause = new QLabel(game);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(20, 245, 50, 50));
        pause->setPixmap(QPixmap(QString::fromUtf8(":/img/pause.png")));
        pause->setScaledContents(true);
        PressP = new QLabel(game);
        PressP->setObjectName(QStringLiteral("PressP"));
        PressP->setGeometry(QRect(80, 250, 100, 40));
        PressP->setFont(font2);

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QWidget *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Form", 0));
        TIME->setText(QApplication::translate("game", "TIME", 0));
        SCORE->setText(QApplication::translate("game", "SCORE", 0));
        red->setText(QString());
        blue->setText(QString());
        PressA->setText(QApplication::translate("game", "Press A", 0));
        PressL->setText(QApplication::translate("game", "Press L", 0));
        pause->setText(QString());
        PressP->setText(QApplication::translate("game", "Press P", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
