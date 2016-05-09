#ifndef TRANSFER_H
#define TRANSFER_H

#include <QDialog>

namespace Ui {
    class Transfer;
}

class Transfer : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer(QWidget *parent = 0);
    ~Transfer();

private:
    Ui::Transfer *ui;
public  slots:
    void  transferAccount();
public:
    void paintEvent(QPaintEvent *e);
};

#endif // TRANSFER_H
