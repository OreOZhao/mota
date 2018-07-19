#include "gamewindow.h"
#include <QDebug>
#include "widget.h"
extern int currentF;
extern Hero* currentH;
int flag[9][11][11];
class Monster;
GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent)
{
    hero=new Hero;
    Block * temp;

}

void GameWindow::keyPressEvent(QKeyEvent *event)
{

    int x=currentH->cpos.x();
    int y=currentH->cpos.y();
    int f=currentF;
    qDebug()<<"hf"<<f<<currentH->getFloor();
    int a=(currentH->cpos.x()-240)/40;
    int b=(currentH->cpos.y()-40)/40;

    {

        switch(event->key())
        {
        //
        case Qt::Key_Up :
            b=b-1;
            if(canArrive(x,y-40)&&flag[f][a][b]==0)
            {
                currentH->setPos(x,y-40);break;
            }else if(canArrive(x,y-40)&&flag[f][a][b]==1)
            {
                bmap[a][b]->action(currentH);
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
                bmap[a][b]->action(currentH);

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
                currentH->setPos(x+40,y);break;
            }else if(canArrive(x+40,y)&&flag[f][a][b]==1)
            {
                bmap[a][b]->action(currentH);
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
                bmap[a][b]->action(currentH);

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
        qDebug()<<currentH->cpos.x()<<currentH->cpos.y();
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

void GameWindow::setMap(int i)//i==floor , loop in the widget constructor
{
    switch(i):
    {
    case 0:
        bmap[4][1]=new Monster(0,35,18,1,1,1);
        bmap[4][3]=new Monster(1,45,20,2,2,2);
        bmap[9][2]=new Monster(1,45,20,2,2,2);
        bmap[2][7]=new Monster(1,45,20,2,2,2);
        bmap[1][3]=new Monster(2,35,38,3,3,3);
        bmap[7][1]=new Monster(2,35,38,3,3,3);
        bmap[4][9]=new Monster(2,35,18,3,3,3);
        bmap[10][0]=new Monster(3,60,32,8,5,5);
        bmap[8][8]=new Monster(4,130,60,3,8,8);
        flag[i][4][1]=1;
        flag[i][4][3]=1;
        flag[i][9][2]=1;
        flag[i][2][7]=1;
        flag[i][1][3]=1;
        flag[i][7][1]=1;
        flag[i][4][9]=1;
        flag[i][10][0]=1;
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
        flag[i][5][6]=1;
        flag[i][5][7]=1;
        flag[i][5][9]=1;
        for(int k=0;k<=9;k++)
            flag[i][k][10]=1;
        flag[i][10][10]=2;
    case 1:
        bmap[0][5]=new Monster(0,35,18,1,1,1);
        bmap[6][4]=new Monster(0,35,18,1,1,1);
        bmap[7][4]=new Monster(0,35,18,1,1,1);
        bmap[9][4]=new Monster(0,35,18,1,1,1);
        bmap[10][4]=new Monster(0,35,18,1,1,1);
        bmap[8][4]=new Monster(1,45,20,2,2,2);
        bmap[3][8]=new Monster(1,45,20,2,2,2);
        bmap[4][8]=new Monster(1,45,20,2,2,2);
        bmap[4][6]=new Monster(2,35,38,3,3,3);
        bmap[10][9]=new Monster(2,35,38,3,3,3);
        bmap[3][7]=new Monster(3,60,32,8,5,5);
        bmap[10][1]=new Monster(3,60,32,8,5,5);

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

        for(int k=0;k<=6;k++)
            flag[i][5][k]=1;

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

        flag[i][0][0]=3;
        flag[i][10][10]=2;

    case 2:
        bmap[5][0]=new Monster(0,35,18,1,1,1);
        bmap[7][3]=new Monster(1,45,20,2,2,2);
        bmap[6][1]=new Monster(1,45,20,2,2,2);
        bmap[10][0]=new Monster(2,35,38,3,3,3);
        bmap[7][6]=new Monster(2,35,38,3,3,3);
        bmap[1][4]=new Monster(2,35,38,3,3,3);
        bmap[5][3]=new Monster(3,60,32,8,5,5);
        bmap[0][10]=new Monster(4,130,60,3,8,8);

        flag[i][5][0]=1;
        flag[i][7][3]=1;
        flag[i][6][1]=1;
        flag[i][10][0]=1;
        flag[i][7][6]=1;
        flag[i][1][4]=1;
        flag[i][5][3]=1;
        flag[i][0][10]=1;

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

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 3:
        bmap[6][5]=new Monster(0,35,18,1,1,1);
        bmap[4][1]=new Monster(1,45,20,2,2,2);
        bmap[10][6]=new Monster(2,35,38,3,3,3);
        bmap[0][10]=new Monster(3,60,32,8,5,5);
        bmap[10][0]=new Monster(3,60,32,8,5,5);
        bmap[2][6]=new Monster(4,130,60,3,8,8);
        bmap[0][7]=new Monster(4,130,60,3,8,8);
        bmap[7][9]=new Monster(4,130,60,3,8,8);

        flag[i][6][5]=1;
        flag[i][4][1]=1;
        flag[i][10][6]=1;
        flag[i][0][10]=1;
        flag[i][10][0]=1;
        flag[i][2][6]=1;
        flag[i][0][7]=1;
        flag[i][7][9]=1;

        for(int k=3;k<=7;k++)
            flag[i][k][0]=1;
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

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 4:
        bmap[7][3]=new Monster(0,35,18,1,1,1);
        bmap[5][0]=new Monster(1,45,20,2,2,2);
        bmap[10][1]=new Monster(4,130,60,3,8,8);
        bmap[0][4]=new Monster(2,35,38,3,3,3);
        bmap[4][8]=new Monster(3,60,32,8,5,5);
        bmap[0][10]=new Monster(5,50,48,12,12,12);

        flag[i][7][3]=1;
        flag[i][5][0]=1;
        flag[i][10][1]=1;
        flag[i][0][4]=1;
        flag[i][4][8]=1;
        flag[i][0][10]=1;

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
       for(int k=8;k<=10;k++)
           flag[i][3][k]=1;
       for(int k=7;k<=9;k++)
           flag[i][k][8]=1;

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 5:
        bmap[2][2]=new Monster(0,35,18,1,1,1);
        bmap[5][2]=new Monster(2,35,38,3,3,3);
        bmap[8][2]=new Monster(1,45,20,2,2,2);
        bmap[4][7]=new Monster(2,35,38,3,3,3);
        bmap[6][7]=new Monster(3,60,32,8,5,5);
        bmap[0][10]=new Monster(4,130,60,3,8,8);
        bmap[6][10]=new Monster(5,50,48,12,12,12);

        flag[i][2][2]=1;
        flag[i][5][2]=1;
        flag[i][8][2]=1;
        flag[i][4][7]=1;
        flag[i][6][7]=1;
        flag[i][0][10]=1;
        flag[i][6][10]=1;

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

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 6:
        bmap[10][0]=new Monster(0,35,18,1,1,1);
        bmap[4][1]=new Monster(2,35,38,3,3,3);
        bmap[0][4]=new Monster(1,45,20,2,2,2);
        bmap[5][4]=new Monster(2,35,38,3,3,3);
        bmap[5][8]=new Monster(3,60,32,8,5,5);
        bmap[8][9]=new Monster(4,130,60,3,8,8);
        bmap[4][10]=new Monster(5,50,48,12,12,12);

        flag[i][10][0]=1;
        flag[i][4][1]=1;
        flag[i][0][4]=1;
        flag[i][5][4]=1;
        flag[i][5][8]=1;
        flag[i][8][9]=1;
        flag[i][4][10]=1;

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

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 7:
        bmap[5][1]=new Monster(7,100,95,30,22,22);
        bmap[9][2]=new Monster(7,100,95,30,22,22);
        bmap[0][3]=new Monster(3,60,32,8,5,5);
        bmap[2][4]=new Monster(7,100,95,30,22);
        bmap[4][5]=new Monster(8,260,85,15,18,18);
        bmap[7][5]=new Monster(4,130,60,3,8,8);
        bmap[10][5]=new Monster(8,260,85,15,18,18);
        bmap[5][9]=new Monster(6,320,120,15,30,30);

        flag[i][5][1]=1;
        flag[i][9][2]=1;
        flag[i][0][3]=1;
        flag[i][2][4]=1;
        flag[i][4][5]=1;
        flag[i][7][5]=1;
        flag[i][10][5]=1;
        flag[i][5][9]=1;

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
        flag[i][7][4]=1;
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

        flag[i][0][0]=3;
        flag[i][10][10]=2;
    case 8:
        bmap[2][0]=new Monster(3,60,32,8,5,5);
        bmap[10][0]=new Monster(9,320,140,15,30,30);
        bmap[6][2]=new Monster(3,60,32,8,5,5);
        bmap[2][3]=new Monster(7,100,95,30,22,22);
        bmap[9][3]=new Monster(8,260,85,15,18,18);
        bmap[7][6]=new Monster(4,130,60,3,8,8);
        bmap[10][7]=new Monster(5,50,48,12,12,12);
        bmap[0][8]=new Monster(6,320,120,15,30,30);
        bmap[6][9]=new Monster(10,500,400,150,300,300);

        flag[i][2][0]=1;
        flag[i][10][0]=1;
        flag[i][6][2]=1;
        flag[i][2][3]=1;
        flag[i][9][3]=1;
        flag[i][7][6]=1;
        flag[i][10][7]=1;
        flag[i][0][8]=1;
        flag[i][6][9]=1;

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

        flag[i][0][0]=3;

    /*
    bmap[1][2][2]=new Block;
    flag[1][2][2]=2;
    bmap[7][3][3]=new Block;
    flag[7][3][3]=2;
    bmap[3][4][4]=new Block;
    flag[3][4][4]=2;
    bmap[8][8][8]=new Block;
    flag[8][8][8]=2;
    */
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
