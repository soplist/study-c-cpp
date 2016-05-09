#include "account.h"
void  Account::setAccountName(QString accountName){
    this->accountName=accountName;
}
void  Account::setAccountNo(QString accountNo){
    this->accountNo=accountNo;
}
void  Account::setAccountPasswd(QString accountPasswd){
    this->accountPasswd=accountPasswd;
}
void  Account::setAccountMoney( double accountMoney){
    this->accountMoney=accountMoney;
}
QString  Account::getAccountName(){
    return accountName;
}
QString  Account::getAccountNo(){
    return accountNo;
}
QString  Account::getAccountPasswd(){
    return accountPasswd;
}
double   Account::getAccountMoney(){
    return accountMoney;
}

Account::Account(){
    accountMoney=0.0;
}
Account::Account(QString  accountName,QString  accountNo,
                 QString  accountPasswd,double   accountMoney){
      this->accountName=accountName;
      this->accountNo=accountNo;
      this->accountPasswd=accountPasswd;
      this->accountMoney=accountMoney;
}
