#ifndef CHANGEPASSWD_H
#define CHANGEPASSWD_H

#include <QDialog>

namespace Ui {
    class ChangePasswd;
}

class ChangePasswd : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswd(QWidget *parent = 0);
    ~ChangePasswd();

private:
    Ui::ChangePasswd *ui;
public slots:
    void  changePasswd();

public:
 void  paintEvent(QPaintEvent *e);
};

#endif // CHANGEPASSWD_H
