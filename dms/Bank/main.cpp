#include <QtGui/QApplication>
#include "adminlogin.h"
#include "adminall.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminLogin w;
    w.show();
    //AdminAll  aa;
   // aa.show();
    return a.exec();
}
