#include "monster.h"

Monster::Monster(int i,int a,int b,int c,int d,int e)
{
    id=i;
    life=a;
    attack=b;
    defence=c;
    money=d;
    experience=e;
    switch(id):
    {
     case 0:
        pix= new QPixmap(":/myMap/image/monster(0)");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                             Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 1:
       pix= new QPixmap(":/myMap/image/monster(1)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 2:
       pix= new QPixmap(":/myMap/image/monster(2)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 3:
       pix= new QPixmap(":/myMap/image/monster(3)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 4:
       pix= new QPixmap(":/myMap/image/monster(4)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 5:
       pix= new QPixmap(":/myMap/image/monster(5)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 6:
       pix= new QPixmap(":/myMap/image/monster(6)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 7:
       pix= new QPixmap(":/myMap/image/monster(7)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 8:
       pix= new QPixmap(":/myMap/image/monster(8)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 9:
       pix= new QPixmap(":/myMap/image/monster(9)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    case 10:
       pix= new QPixmap(":/myMap/image/monster(10)");
       pix->scaledToHeight(40);
       this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);

}

void Monster::action(Hero* hero)
{
     int turn=life/(hero->getAtt()-defence);
     hero->setLife(hero->getLife()-turn*(attack-hero->getDef())*attack);
     hero->setMoney(hero->getMoney()+money);
     hero->setExp(hero->getExp()+experience);
     hide();
     move(0,0);
}
