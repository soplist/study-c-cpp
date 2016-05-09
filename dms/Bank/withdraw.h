#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QDialog>

namespace Ui {
    class WithDraw;
}

class WithDraw : public QDialog
{
    Q_OBJECT

public:
    explicit WithDraw(QWidget *parent = 0);
    ~WithDraw();

private:
    Ui::WithDraw *ui;
public:
 void  paintEvent(QPaintEvent *e);
public slots:
 void  changeAccount();
};

#endif // WITHDRAW_H
