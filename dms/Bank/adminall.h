#ifndef ADMINALL_H
#define ADMINALL_H

#include <QDialog>

namespace Ui {
    class AdminAll;
}

class AdminAll : public QDialog
{
    Q_OBJECT

public:
    explicit AdminAll(QWidget *parent = 0);
    ~AdminAll();

private:
    Ui::AdminAll *ui;
public slots:
    void  createAccount();
    void  seachAccount();
    void  transferAccount();
    void  forDeposite();
    void  withDraw();
    void  changePasswd();
/*给界面增加图片*/
void  paintEvent(QPaintEvent *e);
};

#endif // ADMINALL_H
