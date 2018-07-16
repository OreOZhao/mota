#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent)
{
    hero = new Hero;
    brick=new Block;

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    int x=hero->cpos.x();
    int y=hero->cpos.y();
    {
        switch(event->key())
        {
        //
        case Qt::Key_Up :
            if(canArrive(x,y-40)){hero->setPos(x,y-40);break;}else {break;}
        case Qt::Key_Down:
            if(canArrive(x,y+40)){hero->setPos(x,y+40);break;}else {break;}
        case Qt::Key_Right:
            if(canArrive(x+40,y)){hero->setPos(x+40,y);break;}else {break;}
        case Qt::Key_Left:
            if(canArrive(x-40,y)){hero->setPos(x-40,y);break;}else {break;}
        }
        //else: action
        update();
        }
}


bool GameWindow::canArrive(qreal x,qreal y)
{
    //true: limited in map && no block.
    //false: out of map or meet block
    //if block, stop and action, no move
    if(x<=200 || x>=680 || y<=0 || y>=480)
        return false;
    return true;

}
bool GameWindow::canArrive(QPointF pos)
{

}
void moveTo(qreal x,qreal y)
{

}
void moveTo(bool right,bool up)
{

}
