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
/*�õ���������  �����ݹ����˻�����
  ���÷������ݿ���� �����ݴ������ݿ�
*/
public slots:
    void   createAccount();
public:
void  paintEvent(QPaintEvent *e);
};

#endif // ADDACCOUNT_H
