#include "floor.h"
#include "block.h"
#include "hero.h"

Floor::Floor(bool u)
{
    up=u;
    if(u)
    {
        pix = new QPixmap(":/floor/upstair.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    }
    else
    {
        pix = new QPixmap(":/floor/downstair.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    }
}

void Floor::action(Hero *hero)
{

}
