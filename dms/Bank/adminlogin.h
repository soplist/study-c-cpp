#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QMainWindow>

namespace Ui {
    class AdminLogin;
}

class AdminLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = 0);
    ~AdminLogin();

private:
    Ui::AdminLogin *ui;
 /*��ɽ�����������߼�*/
public slots:
    void   adminLogin();
void  paintEvent(QPaintEvent *e);
};

#endif // ADMINLOGIN_H
