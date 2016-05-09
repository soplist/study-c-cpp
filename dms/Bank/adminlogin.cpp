#include "adminlogin.h"
#include "ui_adminlogin.h"
#include  "adminall.h"
#include  "admindao.h"
#include "admin.h"
#include <QPainter>
#include <QImage>
AdminLogin::AdminLogin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
    connect(ui->login,SIGNAL(clicked()),
            this,SLOT(adminLogin()));
    connect(ui->cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

AdminLogin::~AdminLogin()
{
    delete ui;
}
void   AdminLogin::adminLogin(){
    /*adminid 和adminpasswd 从数据库中查询出来
      得到登陆界面的输入数据 做判断
      登陆成功  关闭登陆界面  进入 主操作界面
   */
    QString  adminid=ui->adminid->text();
    QString  adminpasswd=ui->adminpasswd->text();
    /*连接数据库 得到管理员的相关信息*/
    AdminDao  adao;
    bool cflag=adao.connectDb("QMYSQL","testdb","127.0.0.1",
                                   3306,"root","");

    if(cflag){
       Admin a=adao.getAdminByIdAndPasswd(adminid,adminpasswd);
       qDebug(a.adminId.toLatin1());
       qDebug(a.adminPasswd.toLatin1());
       if(a.adminId==a.adminId
          && a.adminPasswd==adminpasswd
          &&a.adminId!="" &&a.adminPasswd!=""){
           AdminAll  aa;
           this->close();
           aa.exec();
        }else{
           qDebug("select db failed");
        }
     }else{
        qDebug("connect db failed");
     }

}
void  AdminLogin::paintEvent(QPaintEvent *e){
    QPainter qp(this);
    QImage  img;
    img.load(":/bank.bmp");
    qp.drawImage(90,20,img);
}
