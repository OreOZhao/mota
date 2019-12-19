#include "widget.h"
#include "ui_widget.h"
#include "info.h"
#include "hero.h"
#include "gamewindow.h"
#include "monster.h"
#include "businessman.h"
#include "shop.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QThread>
#include "mbhero.h"

Hero *currentH;
extern int currentF;
extern int flag[9][11][11];
extern int a;
extern int b;
class businessMan;
class shop;
class mbHero;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    businessMan *bus1=new businessMan(1);
    businessMan *bus2=new businessMan(2);
    businessMan *bus3=new businessMan(3);
    businessMan *bus4=new businessMan(1);
    mbHero *duke=new mbHero;
    //scene & view
    scene = new QGraphicsScene(this);
    for(int i=0;i<9;i++){
        client[i] =  new GameWindow(this);//view
        client[i]->setMap(i);
        if(i==0){
            client[0]->bmap[3][3]=bus1;
            flag[0][3][3]=1;

        }
        if(i==1){
            client[1]->bmap[0][10]=bus3;
            flag[1][0][10]=1;
        }
        if(i==2){
            client[2]->bmap[10][8]=bus4;
            flag[2][10][8]=1;
        }
        if(i==6){
            client[6]->bmap[0][10]=bus2;
            flag[6][0][10]=1;
        }
        if(i==8){
            client[8]->bmap[8][4]=duke;
            flag[8][8][4]=1;
        }
        client[i]->scene = scene;
        client[i]->setScene(scene);
        client[i]->resize(720,520);
        client[i]->setMinimumSize(360,260);
        client[i]->setMaximumSize(720,520);
        client[i]->setFixedHeight(520);  //view
        client[i]->setFixedWidth(720);
        client[i]->scene->setSceneRect(0,0,720,520); //scene
        connect(client[i],&GameWindow::changed,this,&Widget::setDisplay);

        //hero
        client[i]->hero->itempix = scene->addPixmap(*client[i]->hero->pix);
        client[i]->hero->setXY(0, 1);
        client[i]->hero->setFloor(i);

        //set itempix to scene
        for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                if(flag[i][x][y]!=0)
                {
                    client[i]->bmap[x][y]->itempix=scene->addPixmap(*client[i]->bmap[x][y]->pix);
                    client[i]->bmap[x][y]->setXY(x,y);
                }
            }
        }

        qDebug()<<flag[2][10][8];
        //show & hide
        if(i==currentF){
            client[i]->show();
            currentH=client[i]->hero;
            currentH->itempix->show();
            client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
        }
        else {
            client[i]->hide();
            client[i]->hero->itempix->hide();
            client[i]->setWindowFlags(Qt::WindowStaysOnBottomHint);
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->hide();
                    }
                }
            }
        }

       // qDebug()<<"client"<<i<<"ok";
    }


    connect(client[currentF],&GameWindow::floorUp,this,&Widget::floUp);
    connect(client[currentF],&GameWindow::floorDown,this,&Widget::floDown);
    connect(client[currentF],&GameWindow::act,this,&Widget::blockAct);

    /*
    connect(&bus1->s.A,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus1->s.B,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus1->s.C,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus1->s.D,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus2->s.A,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus2->s.B,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus2->s.C,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus2->s.D,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus3->s.A,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus3->s.B,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus3->s.C,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus3->s.D,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus4->s.A,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus4->s.B,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus4->s.C,&QPushButton::released,this,&Widget::setDisplay);
    connect(&bus4->s.D,&QPushButton::released,this,&Widget::setDisplay);

    connect(&bus1->s.A,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus1->s.B,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus1->s.C,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus1->s.D,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus2->s.A,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus2->s.B,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus2->s.C,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus2->s.D,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus3->s.A,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus3->s.B,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus3->s.C,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus3->s.D,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus4->s.A,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus4->s.B,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus4->s.C,&QPushButton::released,this,&Widget::focusMe);
    connect(&bus4->s.D,&QPushButton::released,this,&Widget::focusMe);
*/

    connect(&bus1->s,&shop::pay,this,&Widget::setDisplay);
    connect(&bus2->s,&shop::pay,this,&Widget::setDisplay);
    connect(&bus3->s,&shop::pay,this,&Widget::setDisplay);
    connect(&bus4->s,&shop::pay,this,&Widget::setDisplay);
    connect(&bus1->s,&shop::pay,this,&Widget::focusMe);
    connect(&bus2->s,&shop::pay,this,&Widget::focusMe);
    connect(&bus3->s,&shop::pay,this,&Widget::focusMe);
    connect(&bus4->s,&shop::pay,this,&Widget::focusMe);
    connect(duke,&mbHero::strong,this,&Widget::focusMe);
    //set display dock
    name=new QLabel("HERO");
    name->move(100,60);
    name->resize(90,40);

    life_1=new QLabel("HP");
    life_1->move(40,100);
    life_1->resize(60,40);
    life=new QLCDNumber();
    life->display(currentH->getLife());
    life->move(100,100);
    life->resize(90,40);

    att_1=new QLabel("ATT");
    att_1->move(40,140);
    att_1->resize(60,40);
    att=new QLCDNumber();
    att->display(currentH->getAtt());
    att->move(100,140);
    att->resize(90,40);

    def_1=new QLabel("DEF");
    def_1->move(40,180);
    def_1->resize(60,40);
    def=new QLCDNumber();
    def->display(currentH->getDef());
    def->move(100,180);
    def->resize(90,40);

    exp_1=new QLabel("EXP");
    exp_1->move(40,220);
    exp_1->resize(60,40);
    exp=new QLCDNumber();
    exp->display(currentH->getExp());
    exp->move(100,220);
    exp->resize(90,40);

    money_1=new QLabel("MONEY");
    money_1->move(40,270);
    money_1->resize(60,40);
    money=new QLCDNumber();
    money->display(currentH->getMoney());
    money->move(100,270);
    money->resize(90,40);

    redk_1=new QLabel("REDK");
    redk_1->move(40,310);
    redk_1->resize(60,40);
    redk=new QLCDNumber();
    redk->display(currentH->getRKey());
    redk->move(100,310);
    redk->resize(90,40);

    bluek_1=new QLabel("BLUEK");
    bluek_1->move(40,350);
    bluek_1->resize(60,40);
    bluek=new QLCDNumber();
    bluek->display(currentH->getBKey());
    bluek->move(100,350);
    bluek->resize(90,40);

    goldk_1=new QLabel("GOLDK");
    goldk_1->move(40,390);
    goldk_1->resize(60,40);
    goldk=new QLCDNumber();
    goldk->display(currentH->getGKey());
    goldk->move(100,390);
    goldk->resize(90,40);

    floor_1=new QLabel("FLOOR");
    floor_1->move(40,450);
    floor_1->resize(60,40);
    floor=new QLCDNumber();
    floor->display(currentH->getFloor());
    floor->move(100,450);
    floor->resize(90,40);

    scene->addWidget(name);
    scene->addWidget(life_1);
    scene->addWidget(att_1);
    scene->addWidget(def_1);
    scene->addWidget(exp_1);
    scene->addWidget(money_1);
    scene->addWidget(redk_1);
    scene->addWidget(bluek_1);
    scene->addWidget(goldk_1);
    scene->addWidget(floor_1);
    scene->addWidget(life);
    scene->addWidget(att);
    scene->addWidget(def);
    scene->addWidget(exp);
    scene->addWidget(money);
    scene->addWidget(redk);
    scene->addWidget(bluek);
    scene->addWidget(goldk);
    scene->addWidget(floor);



}

Widget::~Widget()
{
    delete ui;

    for(int i=0;i<9;i++)
    {
       // qDebug()<<"delete "<<i;
        for(int x=0;x<11;x++)
        {
            for(int y=0;y<11;y++)
            {
                if(flag[i][x][y]!=0)
                {

                    delete client[i]->bmap[x][y];
                }
            }
        }
    }
}
/*
void Widget::paintEvent(QPaintEvent *event)
{
    for(int i=0;i<9;i++){
    client[i]->setFixedHeight(520);
    client[i]->setFixedWidth(720);
    }
    mapWidth=this->width();
    mapHeight=this->height();
}
*/
void Widget::floUp()
{
    qDebug()<<currentF<<"upupup";
    client[currentF]->hero->itempix->hide();
    currentF++;
    currentH=client[currentF]->hero;
    currentH->setFloor(currentF);
    client[currentF]->hero->copyHero(client[currentF-1]->hero);
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    floor->display(currentH->getFloor());
    qDebug()<<"flo up current hero"<<currentH;
    qDebug()<<"flo up this hero"<<client[currentF]->hero;
    for(int i=0;i<9;i++){
        if(i==currentF){
            client[i]->show();
            currentH->itempix->show();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
        }
        else{
            client[i]->hide();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->hide();
                    }
                }
            }
        }
    }
    update();

}

void Widget::floDown()
{

    qDebug()<<currentF<<"downdowndown";
    currentH->itempix->hide();
    currentF--;
    currentH=client[currentF]->hero;

    for(int i=0;i<9;i++){
        if(i==currentF){
            client[i]->show();
            currentH->itempix->show();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
        }
        else{
            client[i]->hide();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->hide();
                    }
                }
            }
        }
    }

   // client[currentF]->hero->setXY(10,9);
    client[currentF]->hero->copyHero(client[currentF+1]->hero);

    qDebug()<<"copied"<<currentH->getLife()<<client[currentF]->hero->getLife();
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    floor->display(currentH->getFloor());
}

//bmap & flag set to static data in gamewindow
//initialize bmap & flag

//currentfloor global variable
/*
void Widget::clear()
{
    qDebug()<<"clear";
}
*
*/

void Widget::setDisplay()
{
    life->display(currentH->getLife());
    att->display(currentH->getAtt());
    def->display(currentH->getDef());
    exp->display(currentH->getExp());
    money->display(currentH->getMoney());
    redk->display(currentH->getRKey());
    //qDebug()<<currentH->getRKey();
    bluek->display(currentH->getBKey());
    goldk->display(currentH->getGKey());

}
void Widget::blockAct()
{
    if(client[currentF]->bmap[a][b]->action(currentH))
    {
        qDebug()<<"action return true";

    }
    else{
        scene->removeItem(client[currentF]->bmap[a][b]->itempix);
        flag[currentF][a][b]=0;
    }
}

void Widget::focusMe()
{
    qDebug()<<"focusme";
    client[currentF]->setFocusPolicy(Qt::FocusPolicy());

}
