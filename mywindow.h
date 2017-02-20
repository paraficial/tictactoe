#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include "board.h"

class MyWindow : public QWidget
{
    Q_OBJECT
public:
    //    explicit MyWindow(QWidget *parent = 0);
    MyWindow(Board *board, QWidget *parent = 0);
    ~MyWindow();
    void updateLabel(QString);


signals:

public slots:

private slots:

private:
    QLabel *statusLabel;

};

#endif // MYWINDOW_H
