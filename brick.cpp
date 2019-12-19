#include "brick.h"
#include "block.h"
#include "hero.h"

Brick::Brick()
{
    pix = new QPixmap(":/brick/brick.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                        Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
}

bool Brick::action(Hero *hero)
{
    return true;
}
