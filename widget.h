#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "gamewindow.h"
#include "info.h"
#include <QGraphicsScene>
#include <QPaintEvent>
#include <QKeyEvent>



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
public slots:
  //  void blockUpdate();
    void floUp();
    void floDown();
};

#endif // WIDGET_H
