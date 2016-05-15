/********************************************************************************
** Form generated from reading UI file 'how.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOW_H
#define UI_HOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_how
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QDialog *how)
    {
        if (how->objectName().isEmpty())
            how->setObjectName(QStringLiteral("how"));
        how->resize(600, 400);
        label = new QLabel(how);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 400));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/how.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(how);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(275, 265, 80, 40));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/me.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(35, 35));
        label_2 = new QLabel(how);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 130, 50, 50));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/bred.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(how);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 180, 50, 50));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/bblue.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(how);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 140, 110, 30));
        label_4->setFont(font);
        label_5 = new QLabel(how);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 190, 110, 30));
        label_5->setFont(font);
        label_6 = new QLabel(how);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 135, 50, 50));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/img/pause.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(how);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(410, 140, 110, 30));
        label_7->setFont(font);

        retranslateUi(how);

        QMetaObject::connectSlotsByName(how);
    } // setupUi

    void retranslateUi(QDialog *how)
    {
        how->setWindowTitle(QApplication::translate("how", "Dialog", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("how", "ok", 0));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QApplication::translate("how", "Press A", 0));
        label_5->setText(QApplication::translate("how", "Press L", 0));
        label_6->setText(QString());
        label_7->setText(QApplication::translate("how", "Press P", 0));
    } // retranslateUi

};

namespace Ui {
    class how: public Ui_how {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOW_H
