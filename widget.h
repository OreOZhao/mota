#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamewindow.h"
#include "info.h"
#include <QGraphicsScene>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QLabel>
#include <QLCDNumber>

namespace Ui {
class Widget;
}

class GameWindow;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent *event);
    GameWindow *client[9];
    QGraphicsScene *scene;

private:
    Ui::Widget *ui;
    QLabel*name;
    QLCDNumber*life;
    QLCDNumber*att;
    QLCDNumber*def;
        QLCDNumber*money;
        QLCDNumber*exp;
        QLCDNumber*redk;
        QLCDNumber*bluek;
        QLCDNumber*goldk;
        QLCDNumber*floor;
        QLabel*life_1;
        QLabel*att_1;
        QLabel*def_1;
        QLabel*money_1;
        QLabel*exp_1;
        QLabel*redk_1;
        QLabel*bluek_1;
        QLabel*goldk_1;
        QLabel*floor_1;
public slots:
    void floUp();
    void floDown();
   // void clear();
    void setDisplay();

};

#endif // WIDGET_H
