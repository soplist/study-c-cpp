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
/*�����û��������Ϣ �õ�һ���˻� ���˻���Ϣ��ֵ������*/
public slots:
    void  seachAccount();
public:
void  paintEvent(QPaintEvent *e);
};

#endif // SEACHACCOUNT_H
