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
    /*adminid ��adminpasswd �����ݿ��в�ѯ����
      �õ���½������������� ���ж�
      ��½�ɹ�  �رյ�½����  ���� ����������
   */
    QString  adminid=ui->adminid->text();
    QString  adminpasswd=ui->adminpasswd->text();
    /*�������ݿ� �õ�����Ա�������Ϣ*/
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
