#ifndef FLOOR_H
#define FLOOR_H

#include <QWidget>
#include "block.h"
#include "hero.h"

class Block;
class Hero;

class Floor:public Block
{

public:
    Floor(bool up);
    bool action(Hero *hero);
private:
    bool up;
};


#endif // FLOOR_H
