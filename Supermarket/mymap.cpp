//mymap.h的实现文件
#include "mymap.h"
#include "ui_mymap.h"
#include <QWidget>
#include <qpainter.h>
#include <QDebug>


Mymap::Mymap(QWidget *parent,int site[100],double adj[100][100],int s,int c)
    :QMainWindow(parent),
    ui(new Ui::Mymap)
{
    ui->setupUi(this);
    this->SupermarketSum = s;
    this->CompanySum = c;
    for(int i=0;i<100;i++)
    {
        this->Site[i] = site[i];
        for(int j=0;j<100;j++)
        {
            this->Adj[i][j] = adj[i][j];
        }
    }

}

Mymap::~Mymap()
{
    delete ui;
}

void Mymap::paintEvent(QPaintEvent *e)
{

    QPainter p(this);
    QImage image(":images/bg.jpg");
    QImage Supermarket(":images/Supermarket.png");
    QImage Company(":images/Company.png");
    p.drawImage(p.window(),image);
    int comHeight = 50.0/600.0*p.window().height();
    int comWidth = 50.0/800.0*p.window().width();
    QPoint arr[] =
    {
        QPoint(50,50),
        QPoint(337.0/800.0*p.window().width(),151.0/600.0*p.window().height()),
        QPoint(322.0/800.0*p.window().width(),295.0/600.0*p.window().height()),
        QPoint(473.0/800.0*p.window().width(),313.0/600.0*p.window().height()),
        QPoint(541.0/800.0*p.window().width(),150.0/600.0*p.window().height()),
        QPoint(208.0/800.0*p.window().width(),122.0/600.0*p.window().height()),
        QPoint(437.0/800.0*p.window().width(),138.0/600.0*p.window().height()),
        QPoint(137.0/800.0*p.window().width(),414.0/600.0*p.window().height()),
        QPoint(678.0/800.0*p.window().width(),209.0/600.0*p.window().height()),
        QPoint(616.0/800.0*p.window().width(),306.0/600.0*p.window().height()),
        QPoint(313.0/800.0*p.window().width(),428.0/600.0*p.window().height())
    };


    QRect first = {0,0,comWidth*4,comHeight};
    ui->menu->clear();
    bool over[CompanySum];
    memset(over,false,sizeof(over));
    for(int i=1;i<=CompanySum;i++)
    {
        QRect rect={arr[i].x(),arr[i].y(),comWidth,comHeight};
        for(int j=1;j<=SupermarketSum;j++)
        {
            if(i==Site[j])
            {
                p.setPen(QPen(Qt::black, 2, Qt::DashDotLine));
                p.setBrush(Qt::CrossPattern);
                p.setFont(QFont("宋体", 13, 10));
                p.drawImage(rect,Supermarket);
                QString text = "超市"+QString::number(j)+"选址为:单位"+QString::number(i);
                temp = new QAction(this);
                temp->setObjectName("temp"+QString::number(j));
                QFont font;
                font.setPointSize(11);
                temp->setFont(font);
                temp->setText(text);
                ui->menu->addAction(temp);
                over[i] = true;
            }
            else if(!over[i])
            {
                p.drawImage(rect, Company);
                over[i] = true;

            }
        }
        p.setPen(QPen(Qt::black, 2, Qt::DashDotLine));
        p.setBrush(Qt::CrossPattern);
        p.setFont(QFont("宋体", 30, 100));
        p.drawText(rect,Qt::AlignCenter|Qt::AlignVCenter,QString::number(i));
    }
    ui->menu_2->clear();
    for(int i=1;i<=CompanySum;i++)
        for(int j=1;j<=CompanySum;j++)
        {
            if(Adj[i][j]!=0&&Adj[i][j]!=100)
            {
                QString text = "单位"+QString::number(i)+"-->单位"+QString::number(j)+":"+QString::number(Adj[i][j]);
                temp = new QAction(this);
                temp->setObjectName("temp"+QString::number(i));
                QFont font;
                font.setPointSize(11);
                temp->setFont(font);
                temp->setText(text);
                ui->menu_2->addAction(temp);
            }
        }

}




