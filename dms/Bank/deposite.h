#ifndef DEPOSITE_H
#define DEPOSITE_H

#include <QDialog>

namespace Ui {
    class Deposite;
}

class Deposite : public QDialog
{
    Q_OBJECT

public:
    explicit Deposite(QWidget *parent = 0);
    ~Deposite();

private:
    Ui::Deposite *ui;
public:
 void  paintEvent(QPaintEvent *e);
public slots:
 void  changeAccount();
};

#endif // DEPOSITE_H
