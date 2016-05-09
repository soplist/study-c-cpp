#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QDialog>

namespace Ui {
    class AddAccount;
}

class AddAccount : public QDialog
{
    Q_OBJECT

public:
    explicit AddAccount(QWidget *parent = 0);
    ~AddAccount();

private:
    Ui::AddAccount *ui;
/*得到界面数据  用数据构建账户对象
  调用访问数据库的类 把数据存入数据库
*/
public slots:
    void   createAccount();
public:
void  paintEvent(QPaintEvent *e);
};

#endif // ADDACCOUNT_H
