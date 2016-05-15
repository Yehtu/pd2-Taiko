#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/img/f.mp3"));
    Init(); //初始化遊戲介面
}

void game::Init()
{
    bgm->play(); //background music
    score = 0;
    combo = 0;
    timeCount = -300; //初始化顯示計時器參數，-300為開始前倒數3秒
    timeDisplay = 30; //設定時間為30秒
    this->ui->LCDtime->display(timeDisplay);
    srand(time(NULL));
    for(int i = 1 ; i < 100 ; ++i)
    {
        x[i] = 750; //初始化鼓的生成位置
        kind[i] = rand()%4; //隨機產生4種鼓
    }
    start_i = 1; //初始化沒有鼓生成
    stop_i = 1;
    allowDrum = 0;
    miss = 0; //初始化判定顯示參數
    wrong = 0;
    ok = 0;
    nice = 0;
    gamepause = false;
    gameTimer = new QTimer(this); //初始化計時器
    connect(gameTimer, SIGNAL(timeout()), this, SLOT(windowUpdate())); //隨時間更新畫面
    gameTimer->start(10); //區間設為100(毫秒)，即每秒刷新10次畫面
}

void game::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, 800, 500, QPixmap(":/img/play.png")); //background
    painter.drawPixmap(130, 60, 60, 60, QPixmap(":/img/target.png")); //target

    if(combo >= 3)
    {
        switch(combo%8)
        {
            case 1: painter.drawPixmap(35, -37, 250, 250, QPixmap(":/img/fire1.png")); break;
            case 2: painter.drawPixmap(35, -35, 250, 250, QPixmap(":/img/fire2.png")); break;
            case 3: painter.drawPixmap(37, -35, 250, 250, QPixmap(":/img/fire3.png")); break;
            case 4: painter.drawPixmap(50, -38, 250, 250, QPixmap(":/img/fire4.png")); break;
            case 5: painter.drawPixmap(36, -35, 250, 250, QPixmap(":/img/fire5.png")); break;
            case 6: painter.drawPixmap(44, -35, 250, 250, QPixmap(":/img/fire6.png")); break;
            case 7: painter.drawPixmap(40, -35, 250, 250, QPixmap(":/img/fire7.png")); break;
            case 0: painter.drawPixmap(36, -36, 250, 250, QPixmap(":/img/fire8.png")); break;
        }
    }

    if(combo >= 5 )
    {
        switch(combo%14)
        {
            case 1: painter.drawPixmap(100,150,80,80,QPixmap(":/img/b2.png"));break;
            case 2: painter.drawPixmap(110,150,80,80,QPixmap(":/img/b3.png"));break;
            case 3: painter.drawPixmap(120,150,80,80,QPixmap(":/img/b4.png"));break;
            case 4: painter.drawPixmap(130,150,80,80,QPixmap(":/img/b5.png"));break;
            case 5: painter.drawPixmap(140,150,80,80,QPixmap(":/img/b6.png"));break;
            case 6: painter.drawPixmap(150,150,80,80,QPixmap(":/img/b7.png"));break;
            case 7: painter.drawPixmap(160,150,80,80,QPixmap(":/img/b8.png"));break;
            case 8: painter.drawPixmap(170,150,80,80,QPixmap(":/img/b9.png"));break;
            case 9: painter.drawPixmap(180,150,80,80,QPixmap(":/img/b10.png"));break;
            case 10: painter.drawPixmap(190,150,80,80,QPixmap(":/img/b11.png"));break;
            case 11: painter.drawPixmap(200,150,80,80,QPixmap(":/img/b12.png"));break;
            case 12: painter.drawPixmap(210,150,80,80,QPixmap(":/img/b13.png"));break;
            case 13: painter.drawPixmap(220,150,80,80,QPixmap(":/img/b14.png"));break;
            case 0: painter.drawPixmap(230,150,80,80,QPixmap(":/img/b1.png"));break;
         }
    }

    for(int i = stop_i-1 ; i >= start_i ; --i) //由後往前生成，避免覆蓋前面的
    {
        switch(kind[i]) //生成鼓
        {
            case 1: painter.drawPixmap(x[i], 65, 45, 45, QPixmap(":/img/sred.png")); break;
            case 2: painter.drawPixmap(x[i], 65, 45, 45, QPixmap(":/img/sblue.png")); break;
            case 3: painter.drawPixmap(x[i], 60, 60, 60, QPixmap(":/img/bred.png")); break;
            case 0: painter.drawPixmap(x[i], 60, 60, 60, QPixmap(":/img/bblue.png")); break;
        }
    }

    if(miss > 0) //沒按到顯示"miss"
    {
        painter.drawPixmap(50, 20, 80, 45, QPixmap(":/img/miss.png"));
        combo = 0;
        --miss;
    }
    if(wrong > 0) //按錯或空按顯示"不可"
    {
        painter.drawPixmap(130, 5, 50, 50, QPixmap(":/img/no.png"));
        combo = 0;
        --wrong;
    }
    if(ok > 0) //顯示"可"
    {
        if(ok > 180) painter.drawPixmap(130, 5, 50, 50, QPixmap(":/img/ok.png"));
        if(ok == 200) ++combo;
        --ok;
    }
    if(nice > 0) //顯示"良"
    {
        if(nice > 180) painter.drawPixmap(130, 5, 50, 50, QPixmap(":/img/nice.png"));
        if(nice == 200) ++combo;
        --nice;
    }

    if(timeCount < 0) //開始前倒數3秒動畫
    {
        if(timeCount < -250)
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count1.png"));
        else if(timeCount < -200)
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count2.png"));
        else if(timeCount < -150)
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count3.png"));
        else if(timeCount < -90)
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count4.png"));
        else if(timeCount < -50)
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count5.png"));
        else
            painter.drawPixmap(150, 45, 520, 325, QPixmap(":/img/count6.png"));
    }
    if(gamepause) //暫停圖示
    {
        painter.drawPixmap(130, 20, 200, 200, QPixmap(":/img/pause.png"));
        painter.drawPixmap(350, 150, 400, 70, QPixmap(":/img/hint.png"));
    }
}

void game::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        //按 A 消紅色鼓
        case Qt::Key_A :
        if((x[start_i] < 160 && kind[start_i] == 1) || (x[start_i] < 150 && kind[start_i] == 3)) //紅色鼓進入判定範圍
        {
            if(kind[start_i] == 1) //小鼓進入判定
            {
                if((x[start_i] > 120 && x[start_i] < 135) || x[start_i] > 145)
                {
                    ++start_i; //該鼓消失
                    ++score; //加一分
                    ok = 200; //顯示"可"
                }
                else if(x[start_i] <= 145 && x[start_i] >= 135)
                {
                    ++start_i; //該鼓消失
                    score = score+2; //加兩分
                    nice = 200; //顯示"良"
                }
            }
            else //大鼓進入判定
            {
                if((x[start_i] > 110 && x[start_i] < 125) || x[start_i] > 135)
                {
                    ++start_i; //該鼓消失
                    ++score; //加一分
                    ok = 200; //顯示"可"
                }
                else if(x[start_i] <= 135 && x[start_i] >= 125)
                {
                    ++start_i; //該鼓消失
                    score = score+2; //加兩分
                    nice = 200; //顯示"良"
                }
            }
        }
        else if((x[start_i] < 160 && kind[start_i] == 0) || (x[start_i] < 150 && kind[start_i] == 2)) //按 A 消藍色鼓
        {
            ++start_i; //該鼓消失
            wrong = 15; //顯示"不可"
        }
        else //判定範圍內無鼓
            wrong = 15; //顯示"不可"
        break;

        //按 L 消藍色鼓
        case Qt::Key_L :
        if((x[start_i] < 160 && kind[start_i] == 0) || (x[start_i] < 150 && kind[start_i] == 2)) //藍色鼓進入判定範圍
        {
            if(kind[start_i] == 0) //小鼓進入判定
            {
                if((x[start_i] > 120 && x[start_i] < 135) || x[start_i] > 145)
                {
                    ++start_i; //該鼓消失
                    ++score; //加一分
                    ok = 200; //顯示"可"
                }
                else if(x[start_i] <= 145 && x[start_i] >= 135)
                {
                    ++start_i; //該鼓消失
                    score = score+2; //加兩分
                    nice = 200; //顯示"良"
                }
            }
            else //大鼓進入判定
            {
                if((x[start_i] > 110 && x[start_i] < 125) || x[start_i] > 135)
                {
                    ++start_i; //該鼓消失
                    ++score; //加一分
                    ok = 200; //顯示"可"
                }
                else if(x[start_i] <= 135 && x[start_i] >= 125)
                {
                    ++start_i; //該鼓消失
                    score = score+2; //加兩分
                    nice = 200; //顯示"良"
                }
            }
        }
        else if((x[start_i] < 160 && kind[start_i] == 0) || (x[start_i] < 150 && kind[start_i] == 2)) //按 L 消紅色鼓
        {
            ++start_i; //該鼓消失
            wrong = 15; //顯示"不可"
        }
        else //判定範圍內無鼓
            wrong = 15; //顯示"不可"
        break;

        //按 P 暫停
        case Qt::Key_P :
        if(timeCount > 0) //開始遊戲才能暫停
        {
            if(gamepause)
            {
                gamepause = false;
                gameTimer->start(10);
            }
            else
            {
                gameTimer->stop();
                gamepause = true;
                update(); }//把timer暫停了，所以要call來重新繪圖
        }
        default: break;
    }
}

void game::windowUpdate()
{
    ++timeCount;
    this->ui->LCDscore->display(score); //update score every time
    if(x[start_i] < 95 && (kind[start_i] == 1 || kind[start_i] == 2)) //沒按到小鼓
    {
        ++start_i; //該鼓消失
        miss = 15; //顯示"miss"
    }
    else if(x[start_i] < 75 && (kind[start_i] == 0 || kind[start_i] == 3)) //沒按到大鼓
    {
        ++start_i; //該鼓消失
        miss = 15; //顯示"miss"
    }

    for(int i = start_i ; i < stop_i ; ++i) //已生成的鼓往左移動
        x[i] = x[i] - 1;
    srand(time(NULL));
    if(allowDrum > 0) --allowDrum;
    else if(timeCount > 0 && ((rand()*timeCount-1)%17 == 0)) //隨機生成鼓
    {
        if(kind[stop_i] == 1 || kind[stop_i] == 2) //下一個是小鼓
        {
            if(kind[stop_i+1] == 0 || kind[stop_i+1] == 3) allowDrum = 50;//且接著大鼓
            else allowDrum = 35; //且接著小鼓
        }
        else //下一個是大鼓
        {
            if(kind[stop_i+1] == 1 || kind[stop_i+1] == 2) allowDrum = 80; //且接著小鼓
            else allowDrum = 50; //且接大鼓
        }
        ++stop_i;
    }
    if(timeCount > 0 && timeCount%100 == 0) //每一秒計時器顯示變動
    {
        this->ui->LCDtime->display(--timeDisplay);
    }
    if(timeDisplay == 0) //time's up
    {
        bgm->stop(); //stop music
        QString result;
        QTextStream(&result) << "Your score : " << score << "\n\n  Play again ?";
        //QMessageBox::setIconPixmap(QPixmap(":/img/meg.png"));
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Time's up !!", result, QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::No) close(); //end game
        else  //Play again
        {
            gameTimer->stop();
            Init();
        }
    }
    update();
}

game::~game()
{
    delete ui;
}
