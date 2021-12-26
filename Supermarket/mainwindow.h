#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mymap.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //打印边权数组，方便debug
    void myDebug();
    //弗洛伊德算法
    void Floyd();
    //加权算法，返回超市index的选址
    int weighting(int index);

//槽函数
protected slots:
    //①的初始化
    void Start();
    //设置单位间距离
    void setDistance();
    //设置公司参数
    void setCompany();
    //初始化参数
    void on_actionInit_triggered();
    //获取地图
    void getMap();

private:
    //绘制ui文件
    Ui::MainWindow *ui;
    //地图窗口指针
    Mymap *mymap;
    //超市总数
    int SupermarketSum;
    //单位总数
    int CompanySum;
    //商品总数
    int GoodSum;
};
#endif // MAINWINDOW_H
