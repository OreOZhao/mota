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

class Hero;
class Block;
class GameWindow : public QGraphicsView
{
    Q_OBJECT
    friend class Hero;
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *scene;
    Hero *hero;
    bool canArrive(qreal x,qreal y);
    bool canArrive(QPointF pos);
    void floorUpdate(int f,bool up);//true up,false down
    int flag[9][11][11]={0};
    Block *bmap[9][11][11];
    //0:    1:block     2:floor
  //  Block *brick;
    void setMap();

signals:
    void meetBlock(int f,int a,int b);
    void floorUp();
    void floorDown();
public slots:
};

#endif // GAMEWINDOW_H
