#include "hero.h"

Hero::Hero(QWidget *parent) : QWidget(parent)
{
    pix= new QPixmap(":/myMap/hero.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);

}

void Hero::setPos(qreal x, qreal y)
{
    cpos.setX(x);
    cpos.setY(y);
    itempix->setPos(cpos);
}

void Hero::fight(Block& monster)
{

    emit pkSignal();
}

void Hero::buy(Block& busiman)
{

    emit buySignal();
}

void Hero::pick(Block &prop)
{
    emit pickSignal();
}

void Hero::setXY(int a,int b)
{
    int x=a*40+240;
    int y=b*40+40;
    setPos(x,y);
}

void Hero::copyHero(Hero *hero)
{
    setRKey(hero->getRKey());
    setGKey(hero->getGKey());
    setBKey(hero->getBKey());
    setAtt(hero->getAtt());
    setDef(hero->getDef());
    setExp(hero->getExp());
    setLife(hero->getLife());
    setLevel(hero->getLevel());
    setMoney(hero->getMoney());

}
