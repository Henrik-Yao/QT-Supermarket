//mainwindow.h的实现文件
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdebug.h>

//存储单位信息
typedef struct Company
{
    int id;        //单位id
    int numberSum; //单位人数
    int rate;      //单位购买商品频度
}Company;

//链表存储超市信息及超市与单位的对应关系
typedef struct Supermarket
{
    int id=0;                   //单位id
    int category=0;             //超市商品种类
    Company* company=nullptr;   //与该超市有关的单位
    Supermarket* next = nullptr;//指向下一个关系
}Supermarket;

//有向边
double Adj[100][100];
//超市与单位的关系链表
Supermarket* phead = new Supermarket;
//存储超市选址，下标为超市id，值为超市选址的单位id
int Site[100];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    memset(Adj,0,sizeof(Adj));
    memset(Site,0,sizeof(Site));
    QLabel *status = new QLabel(tr("develop@Henrik-Yao"));
    statusBar()->addWidget(status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Start()
{
    this->SupermarketSum = ui->SupermarketlineEdit->text().toInt();
    this->CompanySum = ui->CompanylineEdit->text().toInt();
    this->GoodSum = ui->GoodslineEdit->text().toInt();
    for(int i=1;i<=CompanySum;i++)
        for(int j=1;j<=CompanySum;j++)
        {
            if(i==j) continue;
            else Adj[i][j] = 100;
        }
    ui->AID->clear();
    ui->BID->clear();
    ui->CompanyID->clear();
    ui->SupermarketID->clear();
    for(int i=1;i<=CompanySum;i++)
    {
        ui->AID->addItem(QString::number(i));
        ui->BID->addItem(QString::number(i));
        ui->CompanyID->addItem(QString::number(i));
    }
    for(int i=1;i<=SupermarketSum;i++)
    {
        ui->SupermarketID->addItem(QString::number(i));
    }

}

void MainWindow::setDistance()
{
    int i = ui->AID->currentText().toInt();
    int j = ui->BID->currentText().toInt();
    Adj[i][j] = ui->Distance->text().toInt();
}

void MainWindow::setCompany()
{
    int CompanyID = ui->CompanyID->currentText().toInt();
    int SupermarketID = ui->SupermarketID->currentText().toInt();
    int CompanySum = ui->CompanySum->text().toInt();
    int Rate = ui->Rate->text().toInt();
    Supermarket* super = new Supermarket;
    super->id = SupermarketID;
    Company* company = new Company;
    company->id = CompanyID;
    company->numberSum = CompanySum;
    company->rate = Rate;
    super->company = company;
    if(phead->next==nullptr)
    {
        phead->next = super;
    }
    else
    {
        super->next = phead->next;
        phead->next = super;
    }
}

void MainWindow::on_actionInit_triggered()
{
    CompanySum = 4;
    SupermarketSum = 2;
    ui->AID->clear();
    ui->BID->clear();
    ui->CompanyID->clear();
    ui->SupermarketID->clear();
    for(int i=1;i<=CompanySum;i++)
    {
        ui->AID->addItem(QString::number(i));
        ui->BID->addItem(QString::number(i));
        ui->CompanyID->addItem(QString::number(i));
    }
    for(int i=1;i<=SupermarketSum;i++)
    {
        ui->SupermarketID->addItem(QString::number(i));
    }
    memset(Adj,0,sizeof(Adj));
    for(int i=1;i<=CompanySum;i++)
        for(int j=1;j<=CompanySum;j++)
        {
            if(i==j) continue;
            else Adj[i][j] = 100;
        }
    Adj[1][2] = 2;
    Adj[1][3] = 6;
    Adj[1][4] = 4;
    Adj[2][3] = 3;
    Adj[3][1] = 7;
    Adj[3][4] = 1;
    Adj[4][1] = 5;
    Adj[4][3] = 12;
    myDebug();
}

void MainWindow::getMap()
{
    myDebug();
    qDebug()<<weighting(1);
    for(int i=1;i<=SupermarketSum;i++)
    {
        Site[i] = weighting(i);
    }
    mymap = new Mymap(this,Site,Adj,SupermarketSum,CompanySum);
    mymap->show();
}

int MainWindow::weighting(int index)
{
    Floyd();
    Supermarket* p = new Supermarket;
    p = phead->next;
    double temp[100][100];
    memset(temp,0,sizeof(temp));
    for(int i=1;i<CompanySum;i++)
        for(int j=1;j<CompanySum;j++)
            temp[i][j] = Adj[i][j];
    while(p!=nullptr)
    {
        if(p->id==index)
        {
            Company* q = new Company;
            q = p->company;
            int weight = q->numberSum * q->rate;
            int id = q->id;
            //qDebug()<<weight;
            for(int i=1;i<=CompanySum;i++)
            {
                temp[i][id] -= weight * 0.1;
                temp[id][i] -= weight * 0.1;
                if(temp[i][id]<0) temp[i][id] = 0;
                if(temp[id][i]<0) temp[id][i] = 0;
            }
        }
        p = p->next;
    }
    int result = 0,min = 1000;
    for(int i=1;i<=CompanySum;i++)
    {
        int tempSum = 0;
        for(int j=1;j<=CompanySum;j++)
        {
            tempSum += temp[i][j];
        }
        if(tempSum<min)
        {
            min = tempSum;
            result = i;
        }
    }
    return result;
}

void MainWindow::myDebug()
{
    qDebug()<<"-----------------";
    for(int x = 1;x<=CompanySum;x++)
    {
        for(int y = 1;y<=CompanySum;y++)
        {
            qDebug()<<Adj[x][y];
        }
        qDebug()<<"-----------------";
    }
}

void MainWindow::Floyd(){
    for(int k=1;k<=CompanySum;k++)
        for(int i=1;i<=CompanySum;i++)
            for(int j=1;j<=CompanySum;j++)
                if(Adj[i][j]>Adj[i][k]+Adj[k][j])
                    Adj[i][j]=Adj[i][k]+Adj[k][j];
}
