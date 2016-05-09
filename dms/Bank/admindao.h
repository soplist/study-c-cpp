#ifndef ADMINDAO_H
#define ADMINDAO_H
#include "admin.h"
#include <QtSql/QSqlDatabase>
/*管理 相关的访问数据库的类*/
class  AdminDao{
    private:
    QSqlDatabase myconn;

    public:
    AdminDao();
    ~AdminDao();
    bool   connectDb(QString dbdriver,QString dbName,
                     QString hostName,int port,
                     QString userName,QString userpasswd);
    Admin  getAdminByIdAndPasswd(QString adminId, QString adminPasswd);

};
#endif // ADMINDAO_H
