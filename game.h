#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QtCore>
#include <Qtgui>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <time.h>
#include <QTimer>
#include <QLabel>
#include <QLCDNumber>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include <QMediaPlayer>

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *); //繪製視窗畫面
    virtual void keyPressEvent(QKeyEvent *event); //鍵盤輸入
    void Init(); //畫面初始化
    ~game();

private:
    Ui::game *ui;
    int score; //得分
    int combo; //combo數
    int timeCount; //顯示計時器參數
    int timeDisplay; //顯示計時器數字
    int x[100]; //第i個鼓的x座標
    int kind[100]; //第i個鼓是哪一種
    int start_i; //目前畫面上有start_i~stop_i個鼓
    int stop_i;
    int allowDrum; //避免生成的鼓太過重疊
    int miss; //是否沒按到
    int wrong; //是否按錯或是空按
    int ok; //顯示"可"
    int nice; //顯示"良"
    bool gamepause; //遊戲暫停
    QTimer *gameTimer; //計時器
    //QMediaPlayer *bgm;

private slots:
    void windowUpdate(); //隨時間更新畫面

};

#endif // GAME_H
