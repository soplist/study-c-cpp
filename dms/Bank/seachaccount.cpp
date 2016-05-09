#include "seachaccount.h"
#include "ui_seachaccount.h"
#include "accountdao.h"
#include <QPainter>
#include <QImage>
SeachAccount::SeachAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeachAccount)
{
    ui->setupUi(this);
    connect(ui->seach,SIGNAL(clicked()),
            this,SLOT(seachAccount()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

SeachAccount::~SeachAccount()
{
    delete ui;
}
void  SeachAccount::seachAccount(){
    /*�õ��û��� �û����֤�� ������*/
    QString  aname=ui->aname->text();
    QString  aid=ui->aid->text();
    QString  apasswd=ui->passwd->text();
    Account  a(aname,aid,apasswd,0.0);
    /*����������Ϣ ����dao���� */
    AccountDao adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","");
    if(cflag){
        a=adao.getAccountByNameAndIdAndPasswd(a);
    }
    ui->money->setText(QString::number(a.getAccountMoney()));
}
void SeachAccount::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,3,img);
}
