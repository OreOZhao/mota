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
        client[i]->scene = scene;
        client[i]->setScene(scene);
        client[i]->resize(720,520);
        client[i]->setMinimumSize(360,260);
        client[i]->setMaximumSize(720,520);
        client[i]->setFixedHeight(520);  //view
        client[i]->setFixedWidth(720);
        client[i]->scene->setSceneRect(0,0,720,520); //scene
 //       client[i]->scene->addPixmap(QPixmap(":/myMap/b.png"));
        //hero
        client[i]->hero->itempix = scene->addPixmap(*client[i]->hero->pix);
        client[i]->hero->setXY(i, 0);
        client[i]->hero->setFloor(i);

        client[i]->setMap(i);
   //     qDebug()<<i<<"add";
        for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                if(flag[i][x][y]!=0)
                {
                client[i]->bmap[x][y]->itempix=scene->addPixmap(*client[i]->bmap[x][y]->pix);
                client[i]->bmap[x][y]->setXY(x,y);
       //         client[i]->scene->addItem(client[i]->bmap[1][1]->itempix);
                }
            }
        }
        if(i==currentF){
            qDebug()<<"currentF:"<<currentF;
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
            qDebug()<<i<<":hide";
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
            client[i]->show();
            client[i]->hero->itempix->show();
            for(int x=0;x<11;x++){
                for(int y=0;y<11;y++){
                    if(flag[i][x][y]!=0){
                        client[i]->bmap[x][y]->itempix->show();
                    }
                }
            }
            currentH=client[currentF]->hero;
            qDebug()<<i<<":show";
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
            qDebug()<<i<<":hide";
        }

    }

    client[currentF]->hero->setXY(0,0);
    client[currentF]->hero->copyHero(client[currentF-1]->hero);

    qDebug()<<"cf"<<currentF<<client[currentF]->isVisible();
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    update();
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
