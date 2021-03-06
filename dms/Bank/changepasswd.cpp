#include "changepasswd.h"
#include "ui_changepasswd.h"
#include "account.h"
#include "accountdao.h"
#include <QMessageBox>
#include <QPainter>
ChangePasswd::ChangePasswd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePasswd)
{
    ui->setupUi(this);
    connect(ui->change,SIGNAL(clicked()),
            this,SLOT(changePasswd()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

ChangePasswd::~ChangePasswd()
{
    delete ui;
}
void  ChangePasswd::changePasswd(){
    Account a(ui->cname->text(),ui->cid->text(),ui->passwd->text(),0.0);
    if(ui->rnpasswd->text()!=ui->npasswd->text()){
         QMessageBox msg;
         msg.setText("repeat new passwd error!");
         msg.exec();
         return;
    }
    AccountDao adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","");
    if(cflag){
        a=adao.getAccountByNameAndIdAndPasswd(a);
        if(a.getAccountName()!=""&&a.getAccountNo()!=""&&a.getAccountPasswd()!=""){
         adao.changePasswdAccount(a,ui->rnpasswd->text());
         this->close();
        }
    }

}

void  ChangePasswd::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,3,img);
}
