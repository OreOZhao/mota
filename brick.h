#ifndef BRICK_H
#define BRICK_H

#include <QWidget>
#include "block.h"
#include "hero.h"

class Block;
class Hero;

class Brick:public Block
{

public:
    Brick();
    bool action(Hero *hero);
};


#endif // BRICK_H
