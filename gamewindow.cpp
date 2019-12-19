#include "gamewindow.h"
#include <QDebug>
#include "widget.h"
#include "hero.h"
#include "monster.h"
#include "block.h"
#include "floor.h"
#include "brick.h"
#include "businessman.h"
#include "prop.h"
#include "door.h"
#include "princess.h"
#include "mbhero.h"

class Monster;
extern int currentF;
extern Hero* currentH;
int flag[9][11][11];
class Block;
class Hero;
class Brick;
class Floor;
class businessMan;
class Prop;
class Door;
class Princess;
class mbHero;
int a=0;
int b=0;

GameWindow::GameWindow(QWidget *parent,int i) : QGraphicsView(parent)
{
    hero=new Hero;
    setMap(i);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWindow::~GameWindow()
{
  //  qDebug()<<"delete hero & focus block";
    delete hero;

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    int x=currentH->cpos.x();
    int y=currentH->cpos.y();
    int f=currentF;
    a=(currentH->cpos.x()-240)/40;
    b=(currentH->cpos.y()-40)/40;
    {
        switch(event->key())
        {
        case Qt::Key_Up :
            b=b-1;
            if(canArrive(x,y-40)&&flag[f][a][b]==0)
            {
                currentH->setPos(x,y-40);break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==1)
            {
                emit act();
                emit changed();
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
                currentH->setPos(x,y+40);break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==1)
            {
                emit act();
                emit changed();
                break;
            }else if(canArrive(x,y+40)&&flag[f][a][b]==2)//floor up
            {
                qDebug()<<"key down up";
                emit floorUp();
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
                currentH->setPos(x+40,y);break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==1)
            {
                emit act();
                emit changed();
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
                currentH->setPos(x-40,y);break;
            }else if(canArrive(x-40,y)&&flag[f][a][b]==1)
            {
                emit act();
                emit changed();
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
/*
void GameWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"mouse";
    emit changed();
}
*/
bool GameWindow::canArrive(qreal x,qreal y)
{
    //true: limited in map
    //false: out of map or meet block
    //if block, stop and action, no move
    if(x<=200 || x>=680 || y<=0 || y>=480)
        return false;
    return true;
}

void GameWindow::setMap(int i)//i==floor , loop in the widget constructor
{
    switch(i)
    {
    case 0:
        //monsters
        bmap[4][1]=new Monster(0);
        bmap[4][3]=new Monster(1);
        bmap[9][2]=new Monster(1);
        bmap[2][7]=new Monster(1);
        bmap[1][3]=new Monster(2);
        bmap[7][1]=new Monster(2);
        bmap[4][9]=new Monster(2);
        bmap[10][0]=new Monster(3);
        bmap[8][8]=new Monster(4);
        flag[i][4][1]=1;
        flag[i][4][3]=1;
        flag[i][9][2]=1;
        flag[i][2][7]=1;
        flag[i][1][3]=1;
        flag[i][7][1]=1;
        flag[i][4][9]=1;
        flag[i][10][0]=1;
        flag[i][8][8]=1;
        //bricks
        bmap[0][4]=new Brick;
        bmap[1][4]=new Brick;
        bmap[3][4]=new Brick;
        bmap[4][4]=new Brick;
        bmap[5][4]=new Brick;
        bmap[6][4]=new Brick;
        bmap[7][4]=new Brick;
        bmap[9][4]=new Brick;
        bmap[10][4]=new Brick;
        bmap[4][0]=new Brick;
        bmap[5][0]=new Brick;
        bmap[6][0]=new Brick;
        bmap[5][1]=new Brick;
        bmap[5][2]=new Brick;
        bmap[5][5]=new Brick;
        bmap[5][7]=new Brick;
        bmap[5][9]=new Brick;

        flag[i][0][4]=1;
        flag[i][1][4]=1;
        flag[i][3][4]=1;
        flag[i][4][4]=1;
        flag[i][5][4]=1;
        flag[i][6][4]=1;
        flag[i][7][4]=1;
        flag[i][9][4]=1;
        flag[i][10][4]=1;
        flag[i][4][0]=1;
        flag[i][5][0]=1;
        flag[i][6][0]=1;
        flag[i][5][1]=1;
        flag[i][5][2]=1;
        flag[i][5][5]=1;
        flag[i][5][7]=1;
        flag[i][5][9]=1;
        for(int k=0;k<=9;k++){
            bmap[k][10]=new Brick;
            flag[i][k][10]=1;
        }
        /*
        bmap[1][1]=new businessMan(1);
        bmap[0][2]=new businessMan(2);
        bmap[0][3]=new businessMan(3);
        flag[i][1][1]=1;
        flag[i][0][2]=1;
        flag[i][0][3]=1;
*/
        //floor
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;



        //props
        bmap[3][0]=new Prop(4);
        bmap[3][1]=new Prop(4);
        bmap[0][9]=new Prop(4);
        bmap[0][8]=new Prop(5);
        bmap[8][3]=new Prop(1);
        bmap[1][9]=new Prop(1);
        bmap[9][3]=new Prop(2);
        bmap[2][9]=new Prop(2);
        bmap[3][9]=new Prop(3);
        bmap[10][3]=new Prop(3);
        flag[i][3][0]=1;
        flag[i][3][1]=1;
        flag[i][0][9]=1;
        flag[i][0][8]=1;
        flag[i][8][3]=1;
        flag[i][1][9]=1;
        flag[i][9][3]=1;
        flag[i][2][9]=1;
        flag[i][3][9]=1;
        flag[i][10][3]=1;
/*
        bmap[3][3]=new businessMan(1);
        flag[i][3][3]=1;
*/
        bmap[8][4]=new Door(2);
        bmap[5][3]=new Door(1);
        bmap[5][8]=new Door(1);
        bmap[2][4]=new Door(1);
        bmap[5][6]=new Door(1);
        flag[i][8][4]=1;
        flag[i][5][3]=1;
        flag[i][5][8]=1;
        flag[i][2][4]=1;
        flag[i][5][6]=1;
        break;
    case 1:
        //monsters

        bmap[0][5]=new Monster(0);
        bmap[6][4]=new Monster(0);
        bmap[7][4]=new Monster(0);
        bmap[9][4]=new Monster(0);
        bmap[10][4]=new Monster(0);
        bmap[8][4]=new Monster(1);
        bmap[3][8]=new Monster(1);
        bmap[4][8]=new Monster(1);
        bmap[4][6]=new Monster(2);
        bmap[10][9]=new Monster(2);
        bmap[3][7]=new Monster(3);
        bmap[10][1]=new Monster(3);

        flag[i][0][5]=1;
        flag[i][6][4]=1;
        flag[i][7][4]=1;
        flag[i][9][4]=1;
        flag[i][10][4]=1;
        flag[i][8][4]=1;
        flag[i][3][8]=1;
        flag[i][4][8]=1;
        flag[i][4][6]=1;
        flag[i][10][9]=1;
        flag[i][3][7]=1;
        flag[i][10][1]=1;

        //bricks
        for(int k=0;k<=6;k++){
            bmap[5][k]=new Brick;
            flag[i][5][k]=1;
        }
        bmap[0][4]=new Brick;
        bmap[2][4]=new Brick;
        bmap[3][4]=new Brick;
        bmap[4][4]=new Brick;
        bmap[6][5]=new Brick;
        bmap[7][5]=new Brick;
        bmap[9][5]=new Brick;
        bmap[10][5]=new Brick;
        bmap[6][6]=new Brick;
        bmap[7][6]=new Brick;
        bmap[9][6]=new Brick;
        bmap[10][6]=new Brick;
        bmap[5][8]=new Brick;
        bmap[5][9]=new Brick;
        bmap[5][10]=new Brick;


        flag[i][0][4]=1;
        flag[i][2][4]=1;
        flag[i][3][4]=1;
        flag[i][4][4]=1;
        flag[i][6][5]=1;
        flag[i][7][5]=1;
        flag[i][9][5]=1;
        flag[i][10][5]=1;
        flag[i][6][6]=1;
        flag[i][7][6]=1;
        flag[i][9][6]=1;
        flag[i][10][6]=1;
        flag[i][5][8]=1;
        flag[i][5][9]=1;
        flag[i][5][10]=1;

        //props
        bmap[2][0]=new Prop(4);
        bmap[3][0]=new Prop(4);
        bmap[8][0]=new Prop(4);
        bmap[9][0]=new Prop(4);
        bmap[8][5]=new Prop(4);
        bmap[8][6]=new Prop(4);
        bmap[7][0]=new Prop(5);
        bmap[0][7]=new Prop(5);
        bmap[6][0]=new Prop(6);
        bmap[4][9]=new Prop(1);
        bmap[6][10]=new Prop(1);
        bmap[4][10]=new Prop(2);
        bmap[6][9]=new Prop(2);
        bmap[10][2]=new Prop(3);
        bmap[10][3]=new Prop(3);
        flag[i][2][0]=1;
        flag[i][3][0]=1;
        flag[i][8][0]=1;
        flag[i][9][0]=1;
        flag[i][8][5]=1;
        flag[i][8][6]=1;
        flag[i][7][0]=1;
        flag[i][0][7]=1;
        flag[i][6][0]=1;
        flag[i][4][9]=1;
        flag[i][6][10]=1;
        flag[i][4][10]=1;
        flag[i][6][9]=1;
        flag[i][10][2]=1;
        flag[i][10][3]=1;
/*
        bmap[0][10]=new businessMan(3);
        flag[i][0][10]=1;
*/

        bmap[5][7]=new Door(2);
        bmap[1][4]=new Door(1);
        bmap[7][7]=new Door(1);
        bmap[8][7]=new Door(1);
        bmap[9][7]=new Door(1);
        flag[i][5][7]=1;
        flag[i][1][4]=1;
        flag[i][7][7]=1;
        flag[i][8][7]=1;
        flag[i][9][7]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 2:
        bmap[5][0]=new Monster(0);
        bmap[7][3]=new Monster(1);
        bmap[6][1]=new Monster(1);
        bmap[10][0]=new Monster(2);
        bmap[7][6]=new Monster(2);
        bmap[1][4]=new Monster(2);
        bmap[5][3]=new Monster(3);
        bmap[0][10]=new Monster(4);
        flag[i][5][0]=1;
        flag[i][7][3]=1;
        flag[i][6][1]=1;
        flag[i][10][0]=1;
        flag[i][7][6]=1;
        flag[i][1][4]=1;
        flag[i][5][3]=1;
        flag[i][0][10]=1;

        bmap[6][0]=new Brick;
        bmap[7][0]=new Brick;
        bmap[8][0]=new Brick;
        bmap[6][1]=new Brick;
        bmap[10][1]=new Brick;
        bmap[10][2]=new Brick;
        bmap[6][3]=new Brick;
        bmap[10][3]=new Brick;
        bmap[5][4]=new Brick;
        bmap[6][4]=new Brick;
        bmap[7][4]=new Brick;
        bmap[8][4]=new Brick;
        bmap[0][5]=new Brick;
        bmap[1][5]=new Brick;
        bmap[2][5]=new Brick;
        bmap[4][5]=new Brick;
        bmap[5][5]=new Brick;
        bmap[6][5]=new Brick;
        bmap[9][5]=new Brick;
        bmap[6][6]=new Brick;
        bmap[6][7]=new Brick;
        bmap[7][7]=new Brick;
        bmap[7][9]=new Brick;
        bmap[7][10]=new Brick;
        flag[i][6][0]=1;
        flag[i][7][0]=1;
        flag[i][8][0]=1;
        flag[i][6][1]=1;
        flag[i][10][1]=1;
        flag[i][10][2]=1;
        flag[i][6][3]=1;
        flag[i][10][3]=1;
        flag[i][5][4]=1;
        flag[i][6][4]=1;
        flag[i][7][4]=1;
        flag[i][8][4]=1;
        flag[i][0][5]=1;
        flag[i][1][5]=1;
        flag[i][2][5]=1;
        flag[i][4][5]=1;
        flag[i][5][5]=1;
        flag[i][6][5]=1;
        flag[i][9][5]=1;
        flag[i][6][6]=1;
        flag[i][6][7]=1;
        flag[i][7][7]=1;
        flag[i][7][9]=1;
        flag[i][7][10]=1;

        bmap[0][2]=new Prop(4);
        bmap[0][3]=new Prop(4);
        bmap[5][10]=new Prop(4);
        bmap[6][10]=new Prop(4);
        bmap[9][0]=new Prop(5);
        bmap[0][6]=new Prop(1);
        bmap[0][7]=new Prop(1);
        bmap[3][10]=new Prop(2);
        bmap[4][10]=new Prop(2);
        bmap[9][4]=new Prop(3);
        bmap[10][4]=new Prop(3);
        flag[i][0][2]=1;
        flag[i][0][3]=1;
        flag[i][5][10]=1;
        flag[i][6][10]=1;
        flag[i][9][0]=1;
        flag[i][0][6]=1;
        flag[i][0][7]=1;
        flag[i][3][10]=1;
        flag[i][4][10]=1;
        flag[i][9][4]=1;
        flag[i][10][4]=1;
/*
        bmap[10][8]=new businessMan(1);
        flag[i][10][8]=1;
*/
        bmap[6][2]=new Door(2);
        bmap[3][5]=new Door(1);
        bmap[8][3]=new Door(1);
        bmap[9][3]=new Door(1);
        bmap[10][5]=new Door(1);
        bmap[7][8]=new Door(1);
        flag[i][6][2]=1;
        flag[i][3][5]=1;
        flag[i][8][3]=1;
        flag[i][9][3]=1;
        flag[i][10][5]=1;
        flag[i][7][8]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 3:
        bmap[6][5]=new Monster(0);
        bmap[4][1]=new Monster(1);
        bmap[10][6]=new Monster(2);
        bmap[0][10]=new Monster(3);
        bmap[10][0]=new Monster(3);
        bmap[2][6]=new Monster(4);
        bmap[0][7]=new Monster(4);
        bmap[7][9]=new Monster(4);

        flag[i][6][5]=1;
        flag[i][4][1]=1;
        flag[i][10][6]=1;
        flag[i][0][10]=1;
        flag[i][10][0]=1;
        flag[i][2][6]=1;
        flag[i][0][7]=1;
        flag[i][7][9]=1;

        for(int k=3;k<=7;k++){
            bmap[k][0]=new Brick;
            flag[i][k][0]=1;
        }
        bmap[3][1]=new Brick;
        bmap[3][2]=new Brick;
        bmap[4][2]=new Brick;
        bmap[7][2]=new Brick;
        bmap[7][3]=new Brick;
        bmap[3][4]=new Brick;
        bmap[6][4]=new Brick;
        bmap[7][4]=new Brick;
        bmap[3][5]=new Brick;
        bmap[7][5]=new Brick;
        bmap[3][6]=new Brick;
        bmap[7][6]=new Brick;
        bmap[9][6]=new Brick;
        bmap[2][7]=new Brick;
        bmap[5][7]=new Brick;
        bmap[7][7]=new Brick;
        bmap[10][7]=new Brick;
        bmap[0][8]=new Brick;
        bmap[1][8]=new Brick;
        bmap[5][8]=new Brick;
        bmap[7][8]=new Brick;
        bmap[8][8]=new Brick;
        bmap[5][9]=new Brick;
        bmap[5][10]=new Brick;
        flag[i][3][1]=1;
        flag[i][3][2]=1;
        flag[i][4][2]=1;
        flag[i][7][2]=1;
        flag[i][7][3]=1;
        flag[i][3][4]=1;
        flag[i][6][4]=1;
        flag[i][7][4]=1;
        flag[i][3][5]=1;
        flag[i][7][5]=1;
        flag[i][3][6]=1;
        flag[i][7][6]=1;
        flag[i][9][6]=1;
        flag[i][2][7]=1;
        flag[i][5][7]=1;
        flag[i][7][7]=1;
        flag[i][10][7]=1;
        flag[i][0][8]=1;
        flag[i][1][8]=1;
        flag[i][5][8]=1;
        flag[i][7][8]=1;
        flag[i][8][8]=1;
        flag[i][5][9]=1;
        flag[i][5][10]=1;

        bmap[3][10]=new Prop(4);
        bmap[4][10]=new Prop(4);
        bmap[6][10]=new Prop(5);
        bmap[0][2]=new Prop(1);
        bmap[1][9]=new Prop(1);
        bmap[2][9]=new Prop(1);
        bmap[8][1]=new Prop(1);
        bmap[9][1]=new Prop(1);
        bmap[10][1]=new Prop(1);
        bmap[0][3]=new Prop(2);
        bmap[1][9]=new Prop(2);
        bmap[2][9]=new Prop(2);
        bmap[8][2]=new Prop(2);
        bmap[9][2]=new Prop(2);
        bmap[10][2]=new Prop(2);
        flag[i][3][10]=1;
        flag[i][4][10]=1;
        flag[i][6][10]=1;
        flag[i][0][2]=1;
        flag[i][1][9]=1;
        flag[i][2][9]=1;
        flag[i][8][1]=1;
        flag[i][9][1]=1;
        flag[i][10][1]=1;
        flag[i][0][3]=1;
        flag[i][1][9]=1;
        flag[i][2][9]=1;
        flag[i][8][2]=1;
        flag[i][9][2]=1;
        flag[i][10][2]=1;

        bmap[6][7]=new Door(2);
        bmap[3][3]=new Door(1);
        bmap[8][6]=new Door(1);
        bmap[7][1]=new Door(1);
        bmap[4][7]=new Door(0);
        flag[i][6][7]=1;
        flag[i][3][3]=1;
        flag[i][8][6]=1;
        flag[i][7][1]=1;
        flag[i][4][7]=1;
        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 4:
        bmap[7][3]=new Monster(0);
        bmap[5][0]=new Monster(1);
        bmap[10][1]=new Monster(4);
        bmap[0][4]=new Monster(2);
        bmap[4][8]=new Monster(3);
        bmap[0][10]=new Monster(5);
        flag[i][7][3]=1;
        flag[i][5][0]=1;
        flag[i][10][1]=1;
        flag[i][0][4]=1;
        flag[i][4][8]=1;
        flag[i][0][10]=1;

        bmap[4][0]=new Brick;
        bmap[4][1]=new Brick;
        bmap[7][1]=new Brick;
        bmap[4][2]=new Brick;
        bmap[6][2]=new Brick;
        bmap[8][2]=new Brick;
        bmap[2][3]=new Brick;
        bmap[4][3]=new Brick;
        bmap[1][4]=new Brick;
        bmap[6][4]=new Brick;
        bmap[9][4]=new Brick;
        bmap[0][5]=new Brick;
        bmap[10][5]=new Brick;
        bmap[5][6]=new Brick;
        bmap[8][6]=new Brick;
        bmap[1][7]=new Brick;
        bmap[2][7]=new Brick;
        bmap[3][7]=new Brick;
        bmap[6][7]=new Brick;
        bmap[9][7]=new Brick;
        bmap[4][5]=new Brick;
        flag[i][4][0]=1;
        flag[i][4][1]=1;
        flag[i][7][1]=1;
        flag[i][4][2]=1;
        flag[i][6][2]=1;
        flag[i][8][2]=1;
        flag[i][2][3]=1;
        flag[i][4][3]=1;
        flag[i][1][4]=1;
        flag[i][6][4]=1;
        flag[i][9][4]=1;
        flag[i][0][5]=1;
        flag[i][10][5]=1;
        flag[i][5][6]=1;
        flag[i][8][6]=1;
        flag[i][1][7]=1;
        flag[i][2][7]=1;
        flag[i][3][7]=1;
        flag[i][6][7]=1;
        flag[i][9][7]=1;
        flag[i][4][5]=1;

        for(int k=8;k<=10;k++){
           flag[i][3][k]=1;
           bmap[3][k]=new Brick;
        }
        for(int k=7;k<=9;k++){
            flag[i][k][8]=1;
            bmap[k][8]=new Brick;
        }

        bmap[0][2]=new Prop(4);
        bmap[0][3]=new Prop(4);
        bmap[10][6]=new Prop(4);
        bmap[2][10]=new Prop(5);
        bmap[0][8]=new Prop(1);
        bmap[0][9]=new Prop(1);
        bmap[8][5]=new Prop(1);
        bmap[1][8]=new Prop(2);
        bmap[1][9]=new Prop(2);
        bmap[9][5]=new Prop(2);
        bmap[2][8]=new Prop(3);
        bmap[2][9]=new Prop(3);
        flag[i][0][2]=1;
        flag[i][0][3]=1;
        flag[i][10][6]=1;
        flag[i][2][10]=1;
        flag[i][0][8]=1;
        flag[i][0][9]=1;
        flag[i][8][5]=1;
        flag[i][1][8]=1;
        flag[i][1][9]=1;
        flag[i][9][5]=1;
        flag[i][2][8]=1;
        flag[i][2][9]=1;

        bmap[4][6]=new Door(2);
        bmap[0][7]=new Door(1);
        bmap[3][3]=new Door(1);
        bmap[4][4]=new Door(1);
        flag[i][4][6]=1;
        flag[i][0][7]=1;
        flag[i][3][3]=1;
        flag[i][4][4]=1;

       //floor
       bmap[0][0]=new Floor(false);
       flag[i][0][0]=3;
       bmap[10][10]=new Floor(true);
       flag[i][10][10]=2;
       break;
    case 5:
        bmap[2][2]=new Monster(0);
        bmap[5][2]=new Monster(0);
        bmap[8][2]=new Monster(1);
        bmap[4][7]=new Monster(2);
        bmap[6][7]=new Monster(3);
        bmap[0][10]=new Monster(4);
        bmap[6][10]=new Monster(5);
        flag[i][2][2]=1;
        flag[i][5][2]=1;
        flag[i][8][2]=1;
        flag[i][4][7]=1;
        flag[i][6][7]=1;
        flag[i][0][10]=1;
        flag[i][6][10]=1;

        bmap[2][1]=new Brick;
        bmap[3][1]=new Brick;
        bmap[7][1]=new Brick;
        bmap[8][1]=new Brick;
        bmap[1][2]=new Brick;
        bmap[4][2]=new Brick;
        bmap[6][2]=new Brick;
        bmap[9][2]=new Brick;
        bmap[0][3]=new Brick;
        bmap[10][3]=new Brick;
        bmap[0][4]=new Brick;
        bmap[5][4]=new Brick;
        bmap[10][4]=new Brick;
        bmap[1][5]=new Brick;
        bmap[5][5]=new Brick;
        bmap[9][5]=new Brick;
        bmap[5][6]=new Brick;
        bmap[0][7]=new Brick;
        bmap[3][7]=new Brick;
        bmap[5][7]=new Brick;
        bmap[7][7]=new Brick;
        bmap[8][7]=new Brick;
        bmap[1][8]=new Brick;
        bmap[3][8]=new Brick;
        bmap[4][8]=new Brick;
        bmap[5][8]=new Brick;
        bmap[8][8]=new Brick;
        bmap[10][8]=new Brick;
        bmap[5][9]=new Brick;
        bmap[3][10]=new Brick;
        bmap[5][10]=new Brick;
        bmap[6][8]=new Brick;
        flag[i][2][1]=1;
        flag[i][3][1]=1;
        flag[i][7][1]=1;
        flag[i][8][1]=1;
        flag[i][1][2]=1;
        flag[i][4][2]=1;
        flag[i][6][2]=1;
        flag[i][9][2]=1;
        flag[i][0][3]=1;
        flag[i][10][3]=1;
        flag[i][0][4]=1;
        flag[i][5][4]=1;
        flag[i][10][4]=1;
        flag[i][1][5]=1;
        flag[i][5][5]=1;
        flag[i][9][5]=1;
        flag[i][5][6]=1;
        flag[i][0][7]=1;
        flag[i][3][7]=1;
        flag[i][5][7]=1;
        flag[i][7][7]=1;
        flag[i][8][7]=1;
        flag[i][1][8]=1;
        flag[i][3][8]=1;
        flag[i][4][8]=1;
        flag[i][5][8]=1;
        flag[i][8][8]=1;
        flag[i][10][8]=1;
        flag[i][5][9]=1;
        flag[i][3][10]=1;
        flag[i][5][10]=1;
        flag[i][6][8]=1;

        bmap[1][10]=new Prop(1);
        bmap[2][10]=new Prop(2);
        bmap[10][0]=new Prop(1);
        bmap[10][1]=new Prop(2);
        bmap[10][2]=new Prop(3);
        flag[i][1][10]=1;
        flag[i][2][10]=1;
        flag[i][10][0]=1;
        flag[i][10][1]=1;
        flag[i][10][2]=1;

        bmap[8][6]=new Door(0);
        bmap[5][3]=new Door(1);
        bmap[2][6]=new Door(1);
        bmap[2][9]=new Door(1);
        flag[i][8][6]=1;
        flag[i][5][3]=1;
        flag[i][2][6]=1;
        flag[i][2][9]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 6:
        bmap[10][0]=new Monster(0);
        bmap[4][1]=new Monster(2);
        bmap[0][4]=new Monster(1);
        bmap[5][4]=new Monster(2);
        bmap[5][8]=new Monster(3);
        bmap[8][9]=new Monster(4);
        bmap[4][10]=new Monster(5);
        flag[i][10][0]=1;
        flag[i][4][1]=1;
        flag[i][0][4]=1;
        flag[i][5][4]=1;
        flag[i][5][8]=1;
        flag[i][8][9]=1;
        flag[i][4][10]=1;

        bmap[5][0]=new Brick;
        bmap[3][1]=new Brick;
        bmap[6][1]=new Brick;
        bmap[3][2]=new Brick;
        bmap[4][2]=new Brick;
        bmap[0][3]=new Brick;
        bmap[1][3]=new Brick;
        bmap[2][3]=new Brick;
        bmap[3][3]=new Brick;
        bmap[4][3]=new Brick;
        bmap[5][3]=new Brick;
        bmap[6][3]=new Brick;
        bmap[7][3]=new Brick;
        bmap[8][3]=new Brick;
        bmap[10][3]=new Brick;
        bmap[3][4]=new Brick;
        bmap[5][5]=new Brick;
        bmap[6][5]=new Brick;
        bmap[8][5]=new Brick;
        bmap[4][6]=new Brick;
        bmap[5][6]=new Brick;
        bmap[9][6]=new Brick;
        bmap[4][7]=new Brick;
        bmap[5][7]=new Brick;
        bmap[6][7]=new Brick;
        bmap[8][7]=new Brick;
        bmap[4][8]=new Brick;
        bmap[9][8]=new Brick;
        bmap[5][9]=new Brick;
        bmap[10][9]=new Brick;
        bmap[4][10]=new Brick;

        flag[i][5][0]=1;
        flag[i][3][1]=1;
        flag[i][6][1]=1;
        flag[i][3][2]=1;
        flag[i][4][2]=1;
        flag[i][0][3]=1;
        flag[i][1][3]=1;
        flag[i][2][3]=1;
        flag[i][3][3]=1;
        flag[i][4][3]=1;
        flag[i][5][3]=1;
        flag[i][6][3]=1;
        flag[i][7][3]=1;
        flag[i][8][3]=1;
        flag[i][10][3]=1;
        flag[i][3][4]=1;
        flag[i][5][5]=1;
        flag[i][6][5]=1;
        flag[i][8][5]=1;
        flag[i][4][6]=1;
        flag[i][5][6]=1;
        flag[i][9][6]=1;
        flag[i][4][7]=1;
        flag[i][5][7]=1;
        flag[i][6][7]=1;
        flag[i][8][7]=1;
        flag[i][4][8]=1;
        flag[i][9][8]=1;
        flag[i][5][9]=1;
        flag[i][10][9]=1;
        flag[i][4][10]=1;

        bmap[0][8]=new Prop(4);
        bmap[0][9]=new Prop(4);
        bmap[9][7]=new Prop(1);
        bmap[10][7]=new Prop(2);
        bmap[10][8]=new Prop(3);
        flag[i][0][8]=1;
        flag[i][0][9]=1;
        flag[i][9][7]=1;
        flag[i][10][7]=1;
        flag[i][10][8]=1;
/*
        bmap[0][10]=new businessMan(2);
        flag[i][0][10]=1;
*/
        bmap[9][3]=new Door(2);
        bmap[3][5]=new Door(1);
        bmap[4][5]=new Door(1);
        bmap[5][10]=new Door(2);
        flag[i][9][3]=1;
        flag[i][3][5]=1;
        flag[i][4][5]=1;
        flag[i][5][10]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 7:
        bmap[5][1]=new Monster(7);
        bmap[9][2]=new Monster(7);
        bmap[0][3]=new Monster(3);
        bmap[2][4]=new Monster(7);
        bmap[4][5]=new Monster(8);
        bmap[7][5]=new Monster(4);
        bmap[10][5]=new Monster(8);
        bmap[5][9]=new Monster(6);
        flag[i][5][1]=1;
        flag[i][9][2]=1;
        flag[i][0][3]=1;
        flag[i][2][4]=1;
        flag[i][4][5]=1;
        flag[i][7][5]=1;
        flag[i][10][5]=1;
        flag[i][5][9]=1;

        bmap[4][0]=new Brick;
        bmap[5][0]=new Brick;
        bmap[4][1]=new Brick;
        bmap[6][1]=new Brick;
        bmap[6][2]=new Brick;
        bmap[10][2]=new Brick;
        bmap[3][3]=new Brick;
        bmap[4][3]=new Brick;
        bmap[8][3]=new Brick;
        bmap[9][3]=new Brick;
        bmap[3][4]=new Brick;
        bmap[5][4]=new Brick;
        bmap[6][4]=new Brick;
     //   bmap[7][4]=new Brick;
        bmap[0][5]=new Brick;
        bmap[2][5]=new Brick;
        bmap[3][5]=new Brick;
        bmap[5][5]=new Brick;
        bmap[2][6]=new Brick;
        bmap[1][7]=new Brick;
        bmap[5][7]=new Brick;
        bmap[6][7]=new Brick;
        bmap[7][7]=new Brick;
        bmap[9][7]=new Brick;
        bmap[10][7]=new Brick;
        bmap[0][8]=new Brick;
        bmap[9][8]=new Brick;
        bmap[9][10]=new Brick;
        flag[i][4][0]=1;
        flag[i][5][0]=1;
        flag[i][4][1]=1;
        flag[i][6][1]=1;
        flag[i][6][2]=1;
        flag[i][10][2]=1;
        flag[i][3][3]=1;
        flag[i][4][3]=1;
        flag[i][8][3]=1;
        flag[i][9][3]=1;
        flag[i][3][4]=1;
        flag[i][5][4]=1;
        flag[i][6][4]=1;
       // flag[i][7][4]=1;
        flag[i][0][5]=1;
        flag[i][2][5]=1;
        flag[i][3][5]=1;
        flag[i][5][5]=1;
        flag[i][2][6]=1;
        flag[i][1][7]=1;
        flag[i][5][7]=1;
        flag[i][6][7]=1;
        flag[i][7][7]=1;
        flag[i][9][7]=1;
        flag[i][10][7]=1;
        flag[i][0][8]=1;
        flag[i][9][8]=1;
        flag[i][9][10]=1;

        bmap[0][2]=new Prop(4);
        bmap[9][0]=new Prop(4);
        bmap[10][0]=new Prop(4);
        bmap[10][1]=new Prop(5);
        bmap[0][6]=new Prop(1);
        bmap[0][7]=new Prop(2);
        bmap[0][9]=new Prop(3);
        bmap[1][9]=new Prop(3);
        bmap[10][8]=new Prop(3);
        bmap[10][9]=new Prop(3);
        flag[i][0][2]=1;
        flag[i][9][0]=1;
        flag[i][10][0]=1;
        flag[i][10][1]=1;
        flag[i][0][6]=1;
        flag[i][0][7]=1;
        flag[i][0][9]=1;
        flag[i][1][9]=1;
        flag[i][10][8]=1;
        flag[i][10][9]=1;

        bmap[5][2]=new Door(1);
        bmap[5][6]=new Door(1);
        bmap[4][6]=new Door(1);
        bmap[4][7]=new Door(1);
        bmap[9][10]=new Door(1);
        bmap[9][9]=new Door(1);
        bmap[8][7]=new Door(2);
        flag[i][5][2]=1;
        flag[i][5][6]=1;
        flag[i][4][6]=1;
        flag[i][4][7]=1;
        flag[i][9][10]=1;
        flag[i][9][9]=1;
        flag[i][8][7]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;
        bmap[10][10]=new Floor(true);
        flag[i][10][10]=2;
        break;
    case 8:
        bmap[2][0]=new Monster(3);
        bmap[10][0]=new Monster(9);
        bmap[6][2]=new Monster(3);
        bmap[2][3]=new Monster(7);
        bmap[9][3]=new Monster(8);
        bmap[7][6]=new Monster(4);
        bmap[10][7]=new Monster(5);
        bmap[0][8]=new Monster(6);
        bmap[9][5]=new Monster(8);
        bmap[6][7]=new Monster(11);
        flag[i][2][0]=1;
        flag[i][10][0]=1;
        flag[i][6][2]=1;
        flag[i][2][3]=1;
        flag[i][9][3]=1;
        flag[i][7][6]=1;
        flag[i][10][7]=1;
        flag[i][0][8]=1;
        flag[i][9][5]=1;
        flag[i][6][7]=1;

        bmap[3][0]=new Brick;
        bmap[4][0]=new Brick;
        bmap[3][1]=new Brick;
        bmap[3][2]=new Brick;
        bmap[5][2]=new Brick;
        bmap[3][3]=new Brick;
        bmap[7][3]=new Brick;
        bmap[8][3]=new Brick;
        bmap[2][4]=new Brick;
        bmap[5][4]=new Brick;
        bmap[7][4]=new Brick;
        bmap[9][4]=new Brick;
        bmap[0][5]=new Brick;
        bmap[3][5]=new Brick;
        bmap[4][5]=new Brick;
        bmap[5][5]=new Brick;
        bmap[7][5]=new Brick;
        bmap[0][6]=new Brick;
        bmap[1][6]=new Brick;
        bmap[9][6]=new Brick;
        bmap[10][6]=new Brick;
        bmap[4][7]=new Brick;
        bmap[7][7]=new Brick;
        bmap[5][8]=new Brick;
        bmap[8][8]=new Brick;
        bmap[4][9]=new Brick;
        bmap[9][9]=new Brick;
        bmap[3][10]=new Brick;
        bmap[10][10]=new Brick;
        flag[i][3][0]=1;
        flag[i][4][0]=1;
        flag[i][3][1]=1;
        flag[i][3][2]=1;
        flag[i][5][2]=1;
        flag[i][3][3]=1;
        flag[i][7][3]=1;
        flag[i][8][3]=1;
        flag[i][2][4]=1;
        flag[i][5][4]=1;
        flag[i][7][4]=1;
        flag[i][9][4]=1;
        flag[i][0][5]=1;
        flag[i][3][5]=1;
        flag[i][4][5]=1;
        flag[i][5][5]=1;
        flag[i][7][5]=1;
        flag[i][0][6]=1;
        flag[i][1][6]=1;
        flag[i][9][6]=1;
        flag[i][10][6]=1;
        flag[i][4][7]=1;
        flag[i][7][7]=1;
        flag[i][5][8]=1;
        flag[i][8][8]=1;
        flag[i][4][9]=1;
        flag[i][9][9]=1;
        flag[i][3][10]=1;
        flag[i][10][10]=1;

        bmap[0][9]=new Prop(1);
        bmap[1][9]=new Prop(1);
        bmap[4][3]=new Prop(1);
        bmap[3][4]=new Prop(1);
        bmap[10][4]=new Prop(1);
        bmap[0][10]=new Prop(2);
        bmap[1][10]=new Prop(2);
        bmap[10][4]=new Prop(2);
        bmap[5][3]=new Prop(2);
        bmap[4][4]=new Prop(2);
        bmap[2][9]=new Prop(3);
        flag[i][0][9]=1;
        flag[i][1][9]=1;
        flag[i][4][3]=1;
        flag[i][3][4]=1;
        flag[i][10][4]=1;
        flag[i][0][10]=1;
        flag[i][1][10]=1;
        flag[i][10][4]=1;
        flag[i][5][3]=1;
        flag[i][4][4]=1;
        flag[i][2][9]=1;

        bmap[6][3]=new Door(1);
        bmap[2][5]=new Door(0);
        bmap[9][5]=new Door(2);
        flag[i][6][3]=1;
        flag[i][2][5]=1;
        flag[i][9][5]=1;

        bmap[9][10]=new Princess;
        flag[i][9][10]=1;
        //bmap[8][4]=new mbHero;
        //flag[i][8][4]=1;

        //floor
        bmap[0][0]=new Floor(false);
        flag[i][0][0]=3;

        break;
    }
 //   qDebug()<<i<<"ok";

}

void GameWindow::pass()
{
    emit changed();
}
