#ifndef MONSTER_H
#define MONSTER_H

#include "widget.h"
#include "block.h"
#include "hero.h"

class Block;
class Hero;

class Monster:public Block
{

public:
     Monster(int id);
     bool action(Hero *hero);
signals:


private:
     int id,life,attack,defence,money,experience;



};

#endif // MONSTER_H
