#include "door.h"

Door::Door(int i)
{
    id=i;
    switch(id)
    {
    case 0:
        pix = new QPixmap(":/keyAndDoor/reddoor.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                        Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 1:
        pix = new QPixmap(":/keyAndDoor/yellowdoor.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 2:
        pix = new QPixmap(":/keyAndDoor/bluedoor.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                            Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }
}

void Door::action(Hero *hero)
{
    switch(id)
    {
    case 0:
        if(hero->getRKey()>0)
        {
            hero->setRKey(hero->getRKey()-1);
            this->deleteLater();
        }
    case 1:
        if(hero->getGKey()>0)
        {
            hero->setGKey(hero->getGKey()-1);
            this->deleteLater();
        }
    case 2:
        if(hero->getBKey()>0)
        {
            hero->setBKey(hero->getBKey()-1);
            this->deleteLater();
        }
    }
}
