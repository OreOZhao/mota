#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent)
{
    hero = new Hero;
    Block * temp;

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    int x=hero->cpos.x();
    int y=hero->cpos.y();
    int f=hero->getFloor();
    int a=(hero->cpos.x()-240)/40;
    int b=(hero->cpos.y()-40)/40;
    {

        switch(event->key())
        {
        //
        case Qt::Key_Up :
            b=b-1;
            if(canArrive(x,y-40)&&flag[f][a][b]==0)
            {
                hero->setPos(x,y-40);break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==1)
            {
                bmap[f][a][b]->action(*hero);
                break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==2)//floor up
            {
                floorUpdate(f,true);
                break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==3)//floor down
            {
                floorUpdate(f,false);
                break;
            }
            else break;
        case Qt::Key_Down:
            b=b+1;
            if(canArrive(x,y+40)&&flag[f][a][b]==0)
            {
                hero->setPos(x,y+40);break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==1)
            {
                bmap[f][a][b]->action(*hero);
                break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==2)//floor up
            {
                floorUpdate(f,true);
                break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==3)//floor down
            {
                floorUpdate(f,false);
                break;
            }
            else break;
        case Qt::Key_Right:
            a=a+1;
            if(canArrive(x+40,y)&&flag[f][a][b]==0)
            {
                hero->setPos(x+40,y);break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==1)
            {
                bmap[f][a][b]->action(*hero);
                break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==2)//floor up
            {
                floorUpdate(f,true);
                break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==3)//floor down
            {
                floorUpdate(f,false);
                break;
            }
            else break;
        case Qt::Key_Left:
            a=a-1;
            if(canArrive(x-40,y)&&flag[f][a][b]==0)
            {
                hero->setPos(x-40,y);break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==1)
            {
                bmap[f][a][b]->action(*hero);

                break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==2)//floor up
            {
                floorUpdate(f,true);
                break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==3)//floor down
            {
                floorUpdate(f,false);
                break;
            }
            else break;
        }
        //else: action
        update();
        }
}


bool GameWindow::canArrive(qreal x,qreal y)
{
    //true: limited in map
    //false: out of map or meet block
    //if block, stop and action, no move
    if(x<=200 || x>=680 || y<=0 || y>=480)
        return false;
    return true;

}

void GameWindow::floorUpdate(int f,bool up)
{

}
