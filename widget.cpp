#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "info.h"
#include "hero.h"
#include "gamewindow.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QThread>
#include "monster.h"
#include<QLabel>
Hero *currentH;
extern int currentF;
extern int flag[9][11][11];
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    // show data

   // QHBoxLayout *layout=new QHBoxLayout;
    /*
    layout->addWidget(ui->Level);
    layout->addWidget(ui->lifeValue);
    layout->addWidget(ui->attackValue);
    layout->addWidget(ui->defenceValue);
    layout->addWidget(ui->money);
    layout->addWidget(ui->experience);
    layout->addWidget(ui->goldKey);
    layout->addWidget(ui->blueKey);
    layout->addWidget(ui->redKey);
    layout->addWidget(ui->floor);
    setLayout(layout);
*/
    //scene & view

    scene = new QGraphicsScene(this);


    for(int i=0;i<9;i++){
        client[i] =  new GameWindow(this);//view
        client[i]->setMap(i);
        client[i]->scene = scene;
        client[i]->setScene(scene);
        client[i]->resize(720,520);
        client[i]->setMinimumSize(360,260);
        client[i]->setMaximumSize(720,520);
        client[i]->setFixedHeight(520);  //view
        client[i]->setFixedWidth(720);
        client[i]->scene->setSceneRect(0,0,720,520); //scene
        //hero
        client[i]->hero->itempix = scene->addPixmap(*client[i]->hero->pix);
        client[i]->hero->setXY(0, 0);
        client[i]->hero->setFloor(i);

        //set itempix to scene
        for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                if(flag[i][x][y]!=0)
                {
                client[i]->bmap[x][y]->itempix=scene->addPixmap(*client[i]->bmap[x][y]->pix);
                client[i]->bmap[x][y]->setXY(x,y);
 //               qDebug()<<i<<"bmap"<<x<<y<<"set";
          //      client[i]->scene->addItem(client[i]->bmap[1][1]->itempix);
                }
            }
        }
        if(i==currentF){
//            qDebug()<<"currentF:"<<currentF;
            client[i]->show();
            client[i]->hero->itempix->show();
            client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
            currentH=client[currentF]->hero;
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
            qDebug()<<i<<":show";
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
//            qDebug()<<i<<":hide";
        }

    }

  //  setLayout(layout);


    client[0]->upF=client[1];
    for(int i=1;i<8;i++)
    {
        client[i]->upF=client[i+1];
        client[i]->downF=client[i-1];
    }
    client[8]->downF=client[7];

    connect(client[currentF],&GameWindow::floorUp,this,&Widget::floUp);
    connect(client[currentF],&GameWindow::floorDown,this,&Widget::floDown);
/*
    for(int i=0;i<9;i++){
        if(i==currentF){
            qDebug()<<currentF;
            client[i]->hide();
     //       client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
            currentH=client[currentF]->hero;
            qDebug()<<i<<":show";
        }
        else {
            client[i]->hide();
     //       client[i]->setWindowFlags(Qt::WindowStaysOnBottomHint);
            qDebug()<<i<<":hide";
        }

    }
    */

    client[0]->show();
    qDebug()<<client[8]->isVisible();
    client[0]->setWindowFlags(Qt::WindowStaysOnBottomHint);

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
}

void Widget::paintEvent(QPaintEvent *event)
{
    for(int i=0;i<9;i++){
    client[i]->setFixedHeight(520);
    client[i]->setFixedWidth(720);
    }
    mapWidth=this->width();
    mapHeight=this->height();
}

/*
void Widget::blockUpdate()
{
    ui->Level->display(client->hero->getLevel());
    ui->Level->raise();
    ui->lifeValue->display(client->hero->getLife());
    ui->attackValue->display(client->hero->getAtt());
    ui->defenceValue->display(client->hero->getDef());
    ui->experience->display(client->hero->getExp());
    ui->money->display(client->hero->getMoney());
    ui->goldKey->display(client->hero->getBKey());
    ui->redKey->display(client->hero->getRKey());
    ui->blueKey->display(client->hero->getBKey());
}
*/

void Widget::floUp()
{
    qDebug()<<currentF<<"upupup";

    currentF++;
    for(int i=0;i<9;i++){
        if(i==currentF){
            client[ i]->show();
            client[i]->hero->itempix->show();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
            currentH=client[currentF]->hero;
  //          qDebug()<<i<<":show";
        }
        else{
            client[i]->hide();
            client[i]->hero->itempix->hide();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->hide();
                    }
                }
            }
   //         qDebug()<<i<<":hide";
        }

    }

    client[currentF]->hero->setXY(0,1);
    client[currentF]->hero->copyHero(client[currentF-1]->hero);

    qDebug()<<"cf"<<currentF<<client[currentF]->isVisible();
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    update();
    floor->display(currentH->getFloor());
    scene->addWidget(floor);
}

void Widget::floDown()
{

    qDebug()<<currentF<<"downdowndown";

    currentF--;
    for(int i=0;i<9;i++){
        if(i==currentF){
            client[i]->show();

            currentH=client[currentF]->hero;
            qDebug()<<i<<":show";
        }
        else{
            client[i]->hide();
            qDebug()<<i<<":hide";
        }
    }
    client[currentF]->hero->setXY(11,11);
    client[currentF]->hero->copyHero(client[currentF+1]->hero);

    qDebug()<<"cf"<<currentF<<client[currentF]->isVisible();
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    update();
}

//bmap & flag set to static data in gamewindow
//initialize bmap & flag

//currentfloor global variable
