#ifndef DOOR_H
#define DOOR_H

#include <QWidget>
#include "block.h"
#include "hero.h"

class Block;
class Hero;

class Door:public Block
{

public:
    Door(int id);//0 red 1 gold 2 blue
    void action(Hero *hero);
private:
    int id;
};


#endif // DOOR_H
