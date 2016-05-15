#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void openNewWindow();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    game *gamewindow;

private slots:
    void on_ExitButton_clicked();
    void on_PlayButton_clicked();
};

#endif // MAINWINDOW_H
