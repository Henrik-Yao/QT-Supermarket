//#include "parameter.h"
//#include "ui_parameter.h"
//#include<qdebug.h>

//typedef struct Company
//{
//    int id;
//    int numberSum;
//    int rate;
//}Company;

//typedef struct Supermarket
//{
//    int id=0;
//    int category=0;
//    Company* company=nullptr;
//    Supermarket* next = nullptr;
//}Supermarket;

//double Adj[100][100];
//Supermarket* phead = new Supermarket;

//int Site[100];


//Parameter::Parameter(QWidget *parent, int a, int b, int c) :
//    QMainWindow(parent),
//    ui(new Ui::Parameter)
//{
//    ui->setupUi(this);
//    this->SupermarketSum = a;
//    this->CompanySum = b;
//    this->GoodSum = c;
//    memset(Adj,0,sizeof(Adj));
//    memset(Site,0,sizeof(Site));

//    for(int i=1;i<=CompanySum;i++)
//        for(int j=1;j<=CompanySum;j++)
//        {
//            if(i==j) continue;
//            else Adj[i][j] = 100;
//        }
//    for(int i=1;i<=CompanySum;i++)
//    {
//        ui->AID->addItem(QString::number(i));
//        ui->BID->addItem(QString::number(i));
//        ui->CompanyID->addItem(QString::number(i));
//    }
//    for(int i=1;i<=SupermarketSum;i++)
//    {
//        ui->SupermarketID->addItem(QString::number(i));
//    }

//}

//Parameter::~Parameter()
//{
//    delete ui;
//}

//void Parameter::setDistance()
//{
//    int i = ui->AID->currentText().toInt();
//    int j = ui->BID->currentText().toInt();
//    Adj[i][j] = ui->Distance->text().toInt();
//}

//void Parameter::setCompany(){
//    int CompanyID = ui->CompanyID->currentText().toInt();
//    int SupermarketID = ui->SupermarketID->currentText().toInt();
//    int CompanySum = ui->CompanySum->text().toInt();
//    int Rate = ui->Rate->text().toInt();
//    Supermarket* super = new Supermarket;
//    super->id = SupermarketID;
//    Company* company = new Company;
//    company->id = CompanyID;
//    company->numberSum = CompanySum;
//    company->rate = Rate;
//    super->company = company;
//    if(phead->next==nullptr)
//    {
//        phead->next = super;
//    }
//    else
//    {
//        super->next = phead->next;
//        phead->next = super;
//    }


//}

//void Parameter::Floyd(){
//    for(int k=1;k<=CompanySum;k++)
//        for(int i=1;i<=CompanySum;i++)
//            for(int j=1;j<=CompanySum;j++)
//                if(Adj[i][j]>Adj[i][k]+Adj[k][j])
//                    Adj[i][j]=Adj[i][k]+Adj[k][j];
//}

//void Parameter::Test()
//{
//    QString s= QString::number(SupermarketSum);
//    QString a = "lalala";
//    //qDebug<<a;
//}

//void Parameter::on_actionInit_triggered()
//{
//    CompanySum = 4;
//    SupermarketSum = 2;
//    ui->AID->clear();
//    ui->BID->clear();
//    ui->CompanyID->clear();
//    ui->SupermarketID->clear();
//    for(int i=1;i<=CompanySum;i++)
//    {
//        ui->AID->addItem(QString::number(i));
//        ui->BID->addItem(QString::number(i));
//        ui->CompanyID->addItem(QString::number(i));
//    }
//    for(int i=1;i<=SupermarketSum;i++)
//    {
//        ui->SupermarketID->addItem(QString::number(i));
//    }
//    memset(Adj,0,sizeof(Adj));
//    for(int i=1;i<=CompanySum;i++)
//        for(int j=1;j<=CompanySum;j++)
//        {
//            if(i==j) continue;
//            else Adj[i][j] = 100;
//        }
//    Adj[1][2] = 2;
//    Adj[1][3] = 6;
//    Adj[1][4] = 4;
//    Adj[2][3] = 3;
//    Adj[3][1] = 7;
//    Adj[3][4] = 1;
//    Adj[4][1] = 5;
//    Adj[4][3] = 12;
//    myDebug();
//}



