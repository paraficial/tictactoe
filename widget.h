#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include "board.h"
#include "board.h"
#include "game.h"

class Widget : public QWidget
{
    Q_OBJECT
public:
    //    explicit MyWidget(QWidget *parent = 0);
    Widget(Board *board, Game *game, QWidget *parent = 0);
    ~Widget();


signals:

public slots:

private slots:

private:
    QComboBox *combo1, *combo2;
    QLabel *statusLabel;

};

#endif // WIDGET_H
