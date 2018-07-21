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
        money=1;
        experience=1;
        pix= new QPixmap(":/myMonster/monster0.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 1:
        life=45;
        attack=20;
        defence=2;
        money=2;
        experience=2;
        pix= new QPixmap(":/myMonster/monster1.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 2:
        life=35;
        attack=38;
        defence=3;
        money=3;
        experience=3;
        pix= new QPixmap(":/myMonster/monster2.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 3:
        life=60;
        attack=32;
        defence=8;
        money=5;
        experience=5;
        pix= new QPixmap(":/myMonster/monster3.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 4:
        life=130;
        attack=60;
        defence=3;
        money=8;
        experience=8;
        pix= new QPixmap(":/myMonster/monster4.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 5:
        life=50;
        attack=48;
        defence=12;
        money=12;
        experience=12;
        pix= new QPixmap(":/myMonster/monster5.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 6:
        life=320;
        attack=120;
        defence=15;
        money=30;
        experience=30;
        pix= new QPixmap(":/myMonster/monster6.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 7:
        life=100;
        attack=95;
        defence=30;
        money=22;
        experience=2;
        pix= new QPixmap(":/myMonster/monster7.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 8:
        life=260;
        attack=85;
        defence=15;
        money=18;
        experience=18;
        pix= new QPixmap(":/myMonster/monster8.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 9:
        life=320;
        attack=140;
        defence=15;
        money=30;
        experience=30;
        pix= new QPixmap(":/myMonster/monster9.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
   case 10:
        life=500;
        attack=400;
        defence=150;
        money=300;
        experience=300;
        pix= new QPixmap(":/myMonster/monster10.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }

}

void Monster::action(Hero* hero)
{
    qDebug()<<"hi monster";
    int turn=life/(hero->getAtt()-defence);

    qDebug()<<turn<<hero->getLife()-turn*(attack-hero->getDef())*attack<<
              "monster";
    if(turn > 0 && (hero->getLife()-turn*(attack-hero->getDef())*attack)>0){
        hero->setLife(hero->getLife()-turn*(attack-hero->getDef())*attack);
        hero->setMoney(hero->getMoney()+money);
        hero->setExp(hero->getExp()+experience);
        emit clearing();
        qDebug()<<hero->getLife();
      //  qDebug()<<"emitted";

    }
    emit changed();
}
