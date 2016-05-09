#include "deposite.h"
#include "ui_deposite.h"
#include <QPainter>
#include "account.h"
#include "accountdao.h"
#include <QMessageBox>
Deposite::Deposite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deposite)
{
    ui->setupUi(this);
    connect(ui->deposite,SIGNAL(clicked()),
            this,SLOT(changeAccount()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

Deposite::~Deposite()
{
    delete ui;
}
void  Deposite::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,3,img);
}
void  Deposite::changeAccount(){
    Account a(ui->dname->text(),ui->did->text(),ui->dpasswd->text(),ui->dmoney->text().toDouble());
    if(a.getAccountMoney()<=0){
         QMessageBox msg;
         msg.setText("deposite  money is invalid!");
         msg.exec();
    }
    AccountDao  adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","abc123");

    if(cflag){
    adao.depositeAccount(a);
    QMessageBox msg;
    msg.setText("deposite success!");
    msg.exec();
    this->close();
    }
}
