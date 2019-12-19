#include "monster.h"
#include "block.h"
#include "hero.h"
#include <QDebug>
Monster::Monster(int i)
{
    id=i;
    switch(id)
    {
    case 0:
        life=35;
        attack=18;
        defence=1;
        money=5;
        experience=10;
        pix= new QPixmap(":/myMonster/monster0.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 1:
        life=45;
        attack=20;
        defence=2;
        money=10;
        experience=20;
        pix= new QPixmap(":/myMonster/monster1.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 2:
        life=35;
        attack=38;
        defence=3;
        money=15;
        experience=20;
        pix= new QPixmap(":/myMonster/monster2.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 3:
        life=60;
        attack=32;
        defence=8;
        money=15;
        experience=20;
        pix= new QPixmap(":/myMonster/monster3.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 4:
        life=130;
        attack=60;
        defence=13;
        money=20;
        experience=30;
        pix= new QPixmap(":/myMonster/monster4.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 5:
        life=50;
        attack=96;
        defence=48;
        money=20;
        experience=30;
        pix= new QPixmap(":/myMonster/monster5.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 6:
        life=320;
        attack=120;
        defence=40;
        money=30;
        experience=30;
        pix= new QPixmap(":/myMonster/monster6.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 7:
        life=400;
        attack=95;
        defence=40;
        money=20;
        experience=30;
        pix= new QPixmap(":/myMonster/monster7.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 8:
        life=560;
        attack=85;
        defence=55;
        money=40;
        experience=30;
        pix= new QPixmap(":/myMonster/monster8.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 9:
        life=600;
        attack=100;
        defence=40;
        money=30;
        experience=30;
        pix= new QPixmap(":/myMonster/monster9.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 10:
        life=500;
        attack=120;
        defence=80;
        money=50;
        experience=100;
        pix= new QPixmap(":/myMonster/monster10.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 11:
        life=999;
        attack=400;
        defence=200;
        money=999;
        experience=999;
        pix= new QPixmap(":/myMonster/tencent.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }
}

bool Monster::action(Hero* hero)
{

    qDebug()<<"hi monster";

    int turn=life/(hero->getAtt()-defence);
    qDebug()<<turn<<hero->getLife()-turn*(attack-hero->getDef())*attack<<
              "monster";
    if(turn >= 0 && (hero->getLife()-turn*(attack-hero->getDef())*attack)>0 && attack-hero->getDef()>=0){
        hero->setLife(hero->getLife()-turn*(attack-hero->getDef())*attack);
        hero->setMoney(hero->getMoney()+money);
        hero->setExp(hero->getExp()+experience);
        qDebug()<<hero->getLife();
      //  qDebug()<<"emitted";
        return false;
    }
    else if(turn >= 0 && (hero->getLife()-turn*(attack-hero->getDef())*attack)>0 && attack-hero->getDef()<0){
        hero->setMoney(hero->getMoney()+money);
        hero->setExp(hero->getExp()+experience);
    }
    else return true;
}
