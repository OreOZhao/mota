#include "monster.h"

Monster::Monster(int a,int b,int c,int d,int e)
{
    life=a;
    attack=b;
    defence=c;
    money=d;
    experience=e;
}
void Monster::Action(Hero& hero)
{
    int run=life/(hero.getAtt()-defence);
    hero.getLife()=hero.getLife()-run*(attack-hero.getDef())*attack;
    hero.getMoney()=hero.getMoney()+money;
    hero.getExp()=hero.getExp()+experience;
    Monster.hide();
}
