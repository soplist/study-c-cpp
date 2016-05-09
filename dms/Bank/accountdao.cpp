#include "accountdao.h"
#include <QtSql/QSqlQuery>
#include <QVariant>
#include "account.h"
#include <QMessageBox>
bool   AccountDao::connectDb(QString dbdriver,QString dbName,
             QString hostName,int port,
             QString userName,QString userpasswd){
    if(QSqlDatabase::contains("GBond"))
     myconn = QSqlDatabase::database("GBond");
    else
     myconn = QSqlDatabase::addDatabase("QMYSQL", "GBond");
     myconn.setDatabaseName(dbName);
     myconn.setHostName(hostName);
     myconn.setPort(port);
     myconn.setUserName(userName);
     myconn.setPassword(userpasswd);
     return  myconn.open();
}
/*create table account (accountname  varchar(30),accountNo  varchar(30),
  accountpaswd varchar(30),accountMoney  double);*/
bool   AccountDao::addAccount(Account account){
    QSqlQuery   qu(myconn);
    qu.prepare("insert into account values(?,?,?,?)");
    qu.bindValue(0,account.getAccountName());
    qu.bindValue(1,account.getAccountNo());
    qu.bindValue(2,account.getAccountPasswd());
    qu.bindValue(3,account.getAccountMoney());

    return qu.exec();
}

Account  AccountDao::getAccountByNameAndIdAndPasswd(Account account){
    QSqlQuery   qu(myconn);
    qu.prepare("select * from account where accountname=? and accountNo=? and accountpaswd=?");
    qu.bindValue(0,account.getAccountName());
    qu.bindValue(1,account.getAccountNo());
    qu.bindValue(2,account.getAccountPasswd());
    Account  a;
    qu.exec();
    if(qu.next()){
        a.setAccountName(qu.value(0).toString());
        a.setAccountNo(qu.value(1).toString());
        a.setAccountPasswd(qu.value(2).toString());
        a.setAccountMoney(qu.value(3).toDouble());
    }
    return a;

}

Account  AccountDao::getAccountByNameAndId(Account account){
    QSqlQuery   qu(myconn);
    qu.prepare("select * from account where accountname=? and accountNo=?");
    qu.bindValue(0,account.getAccountName());
    qu.bindValue(1,account.getAccountNo());
    Account  a;
    qu.exec();
    if(qu.next()){
        a.setAccountName(qu.value(0).toString());
        a.setAccountNo(qu.value(1).toString());
        a.setAccountPasswd(qu.value(2).toString());
        a.setAccountMoney(qu.value(3).toDouble());
    }
    return a;

}
void     AccountDao::transferByAccount(Account sender,Account recever,double money){
    myconn.transaction();
    QSqlQuery   qu(myconn);
    qu.prepare("update account set accountMoney=accountMoney-? where  accountname=?");
    qu.bindValue(0,money);
    qu.bindValue(1,sender.getAccountName());
    bool f=qu.exec();

    qu.prepare("update account set accountMoney=accountMoney+? where  accountname=?");
    qu.bindValue(0,money);
    qu.bindValue(1,recever.getAccountName());
    bool ff=qu.exec();
    if(f&&ff){
    qDebug("success!");
    myconn.commit();
    }else{
    qDebug("failed!");
    myconn.rollback();
    }
}

void     AccountDao::depositeAccount(Account account){
    QSqlQuery   qu(myconn);
    Account  temp=getAccountByNameAndIdAndPasswd(account);
    if(temp.getAccountName()=="" && temp.getAccountNo()=="" && temp.getAccountPasswd()==""){
         QMessageBox  msg;
         msg.setText("deposite account not exist!");
         msg.exec();
         return;
    }
    qu.prepare("update account set accountMoney=accountMoney+? where  accountname=? and accountNo=? and accountpaswd=?");
    qu.bindValue(0,account.getAccountMoney());
    qu.bindValue(1,account.getAccountName());
    qu.bindValue(2,account.getAccountNo());
    qu.bindValue(3,account.getAccountPasswd());
    bool f=qu.exec();
    if(f){
        QMessageBox  msg;
        msg.setText("deposite success!");
        msg.exec();
    }
}
void     AccountDao::withdrawAccount(Account account){
    QSqlQuery   qu(myconn);
    Account  temp=getAccountByNameAndIdAndPasswd(account);
    if(temp.getAccountName()=="" && temp.getAccountNo()=="" && temp.getAccountPasswd()==""){
         QMessageBox  msg;
         msg.setText("withdraw account not exist!");
         msg.exec();
         return;
    }
    if(account.getAccountMoney()<=0){
        QMessageBox  msg;
        msg.setText("withdraw money is  invalid!");
        msg.exec();
        return;
    }
    qu.prepare("update account set accountMoney=accountMoney-? where  accountname=? and accountNo=? and accountpaswd=?");
    qu.bindValue(0,account.getAccountMoney());
    qu.bindValue(1,account.getAccountName());
    qu.bindValue(2,account.getAccountNo());
    qu.bindValue(3,account.getAccountPasswd());
    bool f=qu.exec();
    if(f){
        QMessageBox  msg;
        msg.setText("withdraw success!");
        msg.exec();
    }
}
void     AccountDao::changePasswdAccount(Account account,QString npasswd){
    QSqlQuery   qu(myconn);
    qu.prepare("update account set accountpaswd=? where  accountname=? and accountNo=? and accountpaswd=?");
    qu.bindValue(0,npasswd);
    qu.bindValue(1,account.getAccountName());
    qu.bindValue(2,account.getAccountNo());
    qu.bindValue(3,account.getAccountPasswd());
    bool f=qu.exec();
    if(f){
        QMessageBox  msg;
        msg.setText("change passwd success!");
        msg.exec();
    }
}
