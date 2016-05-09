#include "adminall.h"
#include "ui_adminall.h"
#include "addaccount.h"
#include "seachaccount.h"
#include "transfer.h"
#include <QPainter>
#include <QImage>
#include "deposite.h"
#include "withdraw.h"
#include "changepasswd.h"
AdminAll::AdminAll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminAll)
{
    ui->setupUi(this);
    connect(ui->createAccount,SIGNAL(clicked()),
            this,SLOT(createAccount()));
    connect(ui->seachAccount,SIGNAL(clicked()),
            this,SLOT(seachAccount()));
    connect(ui->changeAccount,SIGNAL(clicked()),
            this,SLOT(transferAccount()));
    connect(ui->deposite,SIGNAL(clicked()),
            this,SLOT(forDeposite()));
    connect(ui->withDraw,SIGNAL(clicked()),
            this,SLOT(withDraw()));
    connect(ui->changPasswd,SIGNAL(clicked()),
            this,SLOT(changePasswd()));
    connect(ui->quit,SIGNAL(clicked()),
            this,SLOT(close()));
}

AdminAll::~AdminAll()
{
    delete ui;
}
void  AdminAll::createAccount(){
    AddAccount  aa;
    //aa.show();
    aa.exec();
}
void   AdminAll::seachAccount(){
    SeachAccount  sa;
    sa.exec();
}

void  AdminAll::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,5,img);
}

void  AdminAll::transferAccount(){
    Transfer  tf;
    tf.exec();
}
void   AdminAll::forDeposite(){
    Deposite  dp;
    dp.exec();
}
void  AdminAll::withDraw(){
    WithDraw  wd;
    wd.exec();
}

void  AdminAll::changePasswd(){
     ChangePasswd  cp;
     cp.exec();
}
