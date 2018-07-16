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
#include "Block.h"

class Hero;
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
    void moveTo(qreal x,qreal y);
    void moveTo(bool right,bool up);
    int map[11][11]={0};
    Block *brick;


signals:

public slots:
};

#endif // GAMEWINDOW_H
