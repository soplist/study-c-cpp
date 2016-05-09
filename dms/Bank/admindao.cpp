
#include <QtSql/QSqlQuery>
#include <QVariant>
#include "admindao.h"
#include "admin.h"
/*�������ݿ�*/
bool AdminDao::connectDb(QString dbdriver,QString dbName,
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
/*�������� ��ѯ��һ������Ա
   create table  admin(adminid  varchar(30),admpasswd  varchar(30));
*/
Admin  AdminDao::getAdminByIdAndPasswd(QString adminId,
 QString adminPasswd){
     /*�������ݿ�����ӵ���ѯ����*/
     QSqlQuery   qu(myconn);
     qu.prepare("select * from admin where adminid=? and admpasswd=?");
     qu.bindValue(0,adminId);
     qu.bindValue(1,adminPasswd);
     Admin  a={0};
     qu.exec();
     if(qu.next()){
         a.adminId=qu.value(0).toString();
         a.adminPasswd=qu.value(1).toString();
     }
     return a;
}
AdminDao::AdminDao(){


}
AdminDao::~AdminDao(){
     myconn.close();
}


