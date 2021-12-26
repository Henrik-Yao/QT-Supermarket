#ifndef MYMAP_H
#define MYMAP_H

#include <QMainWindow>
#include <QPaintEvent>


namespace Ui {
class Mymap;
}

class Mymap : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mymap(QWidget *parent = nullptr,int site[100] = nullptr,double adj[100][100] = nullptr,int s=0,int c = 0);
    ~Mymap();
    void paintEvent(QPaintEvent *e);
    void drawArrow(QPoint startPoint, QPoint endPoint, QPainter &p);

private:
    //构建ui
    Ui::Mymap *ui;
    //状态栏项目指针
    QAction *temp;
    //超市选址集合
    int Site[100];
    //边权集合
    int Adj[100][100];
    //超市总数
    int SupermarketSum;
    //公司总数
    int CompanySum;
};

#endif // MYMAP_H
