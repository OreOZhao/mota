#include "gamewindow.h"
#include <QDebug>
#include "widget.h"
extern int currentF;
GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent)
{
    hero=new Hero;
    Block * temp;

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    int x=hero->cpos.x();
    int y=hero->cpos.y();
    int f=currentF;
    qDebug()<<"hf"<<f;
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
                bmap[f][a][b]->action(hero);
                break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==2)//floor up
            {
                emit floorUp();
                break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==3)//floor down
            {
                emit floorDown();
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
                bmap[f][a][b]->action(hero);
                break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==2)//floor up
            {
                emit floorUp();
                qDebug()<<"up";
                break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==3)//floor down
            {
                emit floorDown();
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
                bmap[f][a][b]->action(hero);
                break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==2)//floor up
            {
                emit floorUp();
                break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==3)//floor down
            {
                emit floorDown();
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
                bmap[f][a][b]->action(hero);

                break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==2)//floor up
            {
                emit floorUp();
                break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==3)//floor down
            {
                emit floorDown();
                break;
            }
            else break;
        }
        update();
        }
}


bool GameWindow::canArrive(qreal x,qreal y)
{
    //true: limited in map
    //false: out of map 
    if(x<=200 || x>=680 || y<=0 || y>=480)
        return false;
    return true;
}

void GameWindow::setMap()
{
    //test
    bmap[0][1][1]=new Block;
    flag[0][1][1]=2;
    bmap[1][2][2]=new Block;
    flag[1][2][2]=2;
    bmap[2][3][3]=new Block;
    flag[2][3][3]=2;
    bmap[3][4][4]=new Block;
    flag[3][4][4]=2;
    bmap[8][8][8]=new Block;//这个可以显示
    flag[8][8][8]=2;
}
/*
void GameWindow::floorUpdate(int f,bool up)
{
    this->setVisible(false);
    qDebug()<<"hide";
    this->upF->setVisible(true);

    qDebug()<<"up";

    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if(flag[f][i][j]!=0)
            {
      //          bmap[f][i][j]->hide();
                qDebug()<<"hide";
            }
        }
    }
    if(up)
        f++;
    else
        f--;
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if(flag[f][i][j]!=0){
                bmap[f][i][j]->show();
                qDebug()<<"show";
            }
        }
    }


}

*/
