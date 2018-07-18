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
Hero *currentH;
extern int currentF;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    // show data
    /*
    QHBoxLayout *layout=new QHBoxLayout;
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
        scene->setSceneRect(0,0,720,520); //scene
        scene->addPixmap(QPixmap(":/myMap/back.png"));

        //hero
        client[i]->hero->itempix = scene->addPixmap(*client[i]->hero->pix);
        client[i]->hero->setXY(0, 0);
        client[i]->hero->setFloor(i);

        client[i]->setMap();
        for(int x=0;x<11;x++){
            for(int y=0;y<11;y++){
                if(client[i]->flag[i][x][y]!=0)
                {
                client[i]->bmap[i][x][y]->itempix=scene->addPixmap(*client[i]->bmap[i][x][y]->pix);
                client[i]->bmap[i][x][y]->setXY(x,y);
                }
            }
        }
    }
    client[0]->upF=client[1];
    for(int i=1;i<8;i++)
    {
        client[i]->upF=client[i+1];
        client[i]->downF=client[i-1];
    }
    client[8]->downF=client[7];

    connect(client[currentF],&GameWindow::floorUp,this,&Widget::floUp);
    connect(client[currentF],&GameWindow::floorDown,this,&Widget::floDown);



    for(int i=0;i<9;i++){
        if(i==currentF){client[i]->show();    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);currentH=client[currentF]->hero;qDebug()<<i<<":show";}
        else {client[i]->hide();    client[i]->setWindowFlags(Qt::WindowStaysOnBottomHint);qDebug()<<i<<":hide";}

    }


}

Widget::~Widget()
{
    delete ui;
}
/*
void Widget::paintEvent(QPaintEvent *event)
{
    client->setFixedHeight(520);
    client->setFixedWidth(720);
    mapWidth=this->width();
    mapHeight=this->height();
}
*/
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
    qDebug()<<"upupup";

    currentF++;
    for(int i=0;i<9;i++){
        if(i==currentF){
            client[i]->show();
            currentH=client[currentF]->hero;
            qDebug()<<i<<":show";
        }
        else {
            client[i]->hide();
            qDebug()<<i<<":hide";
        }
    }

    qDebug()<<client[8]->isVisible();
    client[currentF]->hero->setXY(0,0);
    client[currentF]->hero->copyHero(client[currentF-1]->hero);



    qDebug()<<"cf"<<currentF<<client[currentF]->isVisible();
    client[currentF]->setWindowFlags(Qt::WindowStaysOnTopHint);
    update();
}

void Widget::floDown()
{

    client[currentF]->setVisible(false);

    client[currentF]->downF->setVisible(true);
    currentF--;
}

//bmap & flag set to static data in gamewindow
//initialize bmap & flag

//currentfloor global variable
