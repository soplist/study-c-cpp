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
 /*完成进入主界面的逻辑*/
public slots:
    void   adminLogin();
void  paintEvent(QPaintEvent *e);
};

#endif // ADMINLOGIN_H
