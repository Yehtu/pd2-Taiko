#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ExitButton_clicked()
{
    close();
}

void MainWindow::on_PlayButton_clicked()
{
    openNewWindow(); //gimewindow
    close();
}

void MainWindow::openNewWindow()
{
   gamewindow = new game();
   gamewindow->setWindowTitle("Taiko");
   gamewindow->setWindowIcon(QIcon(":/img/icon.png"));
   gamewindow->show();
}
