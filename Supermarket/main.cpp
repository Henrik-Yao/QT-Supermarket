#include "mainwindow.h"
#include "mymap.h"
#include <QApplication>

//窗体主函数,实现窗体启动
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
