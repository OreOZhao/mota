#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include "hero.h"
#include <QGraphicsView>
#include <QPointF>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsItemGroup>
#include "block.h"
#include "widget.h"
extern int currentF;
class Hero;
class Block;
class Widget;
class GameWindow : public QGraphicsView
{
    Q_OBJECT

//    static Hero *hero;
public:

    explicit GameWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *scene;
    GameWindow *upF;
    GameWindow *downF;
    Hero* hero;
    bool canArrive(qreal x,qreal y);
    bool canArrive(QPointF pos);
    int flag[9][11][11]={0};
    Block *bmap[9][11][11];
    //0:    1:block     2:floorup   3:down

    void setMap();

signals:
    void meetBlock(int f,int a,int b);
    void floorUp();
    void floorDown();
public slots:
};

#endif // GAMEWINDOW_H
