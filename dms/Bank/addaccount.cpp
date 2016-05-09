#include "addaccount.h"
#include "ui_addaccount.h"
#include "account.h"
#include "accountdao.h"
#include <QMessageBox>
#include <QPainter>
#include <QImage>
AddAccount::AddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAccount)
{
    ui->setupUi(this);
    connect(ui->createAccount,SIGNAL(clicked()),
            this,SLOT(createAccount()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

AddAccount::~AddAccount()
{
    delete ui;
}

void   AddAccount::createAccount(){
    /*�õ�����*/
    QString  aname=ui->accountName->text();
    QString  aid=ui->accountId->text();
    QString  apaswd=ui->accountPasswd->text();
    Account  a(aname,aid,apaswd,0.0);
    /*���÷������ݿ�Ķ��� �Ѷ���������ݿ�*/
    AccountDao adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","");
    if(cflag){
       bool f=adao.addAccount(a);
       if(f){
       QMessageBox  msg(this);
       msg.setText("create account success!!");
       msg.exec();
       }else{
        QMessageBox  msg(this);
        msg.setText("create account failed!!");
        msg.exec();
       }
    }
    this->close();
}


void  AddAccount::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,5,img);
}