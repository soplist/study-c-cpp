#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H
#include <QtSql/QSqlDatabase>
#include "account.h"
#include <QString>
class AccountDao{
    private:
    QSqlDatabase myconn;

    public:

    bool   connectDb(QString dbdriver,QString dbName,
                 QString hostName,int port,
                 QString userName,QString userpasswd);
    bool   addAccount(Account account);
    Account  getAccountByNameAndIdAndPasswd(Account account);
    Account  getAccountByNameAndId(Account account);
    void     transferByAccount(Account sender,Account recever,double money);
    void     depositeAccount(Account account);
    void     withdrawAccount(Account account);
    void     changePasswdAccount(Account account,QString npasswd);
};
#endif // ACCOUNTDAO_H
