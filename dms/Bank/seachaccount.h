#ifndef SEACHACCOUNT_H
#define SEACHACCOUNT_H

#include <QDialog>

namespace Ui {
    class SeachAccount;
}

class SeachAccount : public QDialog
{
    Q_OBJECT

public:
    explicit SeachAccount(QWidget *parent = 0);
    ~SeachAccount();

private:
    Ui::SeachAccount *ui;
/*根据用户输入的信息 得到一个账户 把账户信息赋值给界面*/
public slots:
    void  seachAccount();
public:
void  paintEvent(QPaintEvent *e);
};

#endif // SEACHACCOUNT_H
