#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPointF>
#include <QKeyEvent>
#include <QWidget>
#include <QGraphicsItemGroup>

#include "widget.h"

extern int currentF;
extern int flag[9][11][11];
class Hero;
class Block;
class Widget;
class Monster;

class GameWindow : public QGraphicsView
{

    Q_OBJECT
public:
    friend class Monster;
    explicit GameWindow(QWidget *parent = nullptr,int floor=0);
    ~GameWindow();
    void keyPressEvent(QKeyEvent *event);
    QGraphicsScene *scene;
    GameWindow *upF;
    GameWindow *downF;
    Hero* hero;
    Block *focusB;
    bool canArrive(qreal x,qreal y);
    Block *bmap[11][11];
    //flag value      0:    1:block     2:floorup   3:down
    void setMap(int i);// i floorNumber

signals:
    void meetBlock(int f,int a,int b);
    void floorUp();
    void floorDown();
public slots:
    void clear();
};

#endif // GAMEWINDOW_H
