#include "widget.h"
#include "ui_widget.h"
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "info.h"
#include "hero.h"
#include "gamewindow.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

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

    scene = new QGraphicsScene(this);
    client =  new GameWindow(this);//view
    client->scene = scene;
    client->setScene(scene);
    client->resize(720,520);
    client->setMinimumSize(360,260);
    client->setMaximumSize(720,520);
    client->setFixedHeight(520);  //view
    client->setFixedWidth(720);
    scene->setSceneRect(0,0,720,520); //scene
    scene->addPixmap(QPixmap(":/myMap/back.png"));

    client->hero->itempix = scene->addPixmap(*client->hero->pix);
    client->hero->setPos(240, 40);
    client->brick->itempix= scene->addPixmap(*client->brick->pix);
    client->brick->setPos(480,80);
    client->show();

    connect(client->hero,&Hero::buySignal,this,&Widget::blockUpdate);
    connect(client->hero,&Hero::pkSignal,this,&Widget::blockUpdate);
    connect(client->hero,&Hero::pickSignal,this,&Widget::blockUpdate);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    client->setFixedHeight(520);
    client->setFixedWidth(720);
    mapWidth=this->width();
    mapHeight=this->height();
}

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
