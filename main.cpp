#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // ================= Setting Windows Size ===========================
    QDesktopWidget wid;
    int screenW = 805;
    int screenH = 535;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("Taiko");
    w.setWindowIcon(QIcon(":/img/icon.png"));
    w.show();

    return a.exec();
}
