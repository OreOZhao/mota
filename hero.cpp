#include "hero.h"

Hero::Hero(QWidget *parent) : QWidget(parent)
{
    pix= new QPixmap(":/myMap/hero.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    emit pickSignal();
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
