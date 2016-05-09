#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
/*对应一个 账户类*/
class  Account{
    private:
        QString  accountName;
        QString  accountNo;
        QString  accountPasswd;
        double   accountMoney;
    public:
        void  setAccountName(QString accountName);
        void  setAccountNo(QString accountNo);
        void  setAccountPasswd(QString accountPasswd);
        void  setAccountMoney(double  accountMoney);
        QString  getAccountName();
        QString  getAccountNo();
        QString  getAccountPasswd();
        double   getAccountMoney();
     public:
        Account();
        Account(QString  accountName,QString  accountNo,
                QString  accountPasswd,double   accountMoney);
};
#endif // ACCOUNT_H
