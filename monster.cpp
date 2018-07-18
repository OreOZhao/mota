#include "monster.h"

Monster::Monster(int a,int b,int c,int d,int e)
{
    life=a;
    attack=b;
    defence=c;
    money=d;
    experience=e;
}

void Monster::action(Hero* hero)
{
     int run=life/(hero->getAtt()-defence);
     hero->setLife(hero->getLife()-run*(attack-hero->getDef())*attack);
     hero->setMoney(hero->getMoney()+money);
     hero->setExp(hero->getExp()+experience);
     hide();
}
