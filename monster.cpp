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
        pix= new QPixmap(":/brick/brick.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    }

}

void Monster::action(Hero* hero)
{
     int run=life/(hero->getAtt()-defence);
     hero->setLife(hero->getLife()-run*(attack-hero->getDef())*attack);
     hero->setMoney(hero->getMoney()+money);
     hero->setExp(hero->getExp()+experience);
     hide();
}
