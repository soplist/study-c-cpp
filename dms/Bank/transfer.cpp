#include "transfer.h"
#include "ui_transfer.h"
#include "account.h"
#include "accountdao.h"
#include <QMessageBox>
#include <QPainter>
Transfer::Transfer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transfer)
{
    ui->setupUi(this);
    connect(ui->transfer,SIGNAL(clicked()),
            this,SLOT(transferAccount()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

Transfer::~Transfer()
{
    delete ui;
}
void  Transfer::transferAccount(){
    /*得到相关的转帐信息 包装成对象
      把这两个账户 传入dao 完成转账
   */
    Account sender;
    sender.setAccountName(ui->sname->text());
    sender.setAccountNo(ui->sno->text());
    sender.setAccountPasswd(ui->spasswd->text());

    Account reciver;
    reciver.setAccountName(ui->rname->text());
    reciver.setAccountNo(ui->rno->text());

    AccountDao adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","");
    if(cflag){
    Account s=adao.getAccountByNameAndIdAndPasswd(sender) ;
    if(s.getAccountMoney()<ui->money->text().toDouble()){
       QMessageBox  msg;
       msg.setText("have not enough money");
       msg.exec();
       return;
    }
    Account r=adao.getAccountByNameAndId(reciver);
    qDebug(r.getAccountName().toLatin1());
     qDebug(s.getAccountName().toLatin1());

    adao.transferByAccount(s,r,ui->money->text().toDouble());
    }

}
void  Transfer::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,0,img);
}
