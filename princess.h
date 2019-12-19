#ifndef PRINCESS_H
#define PRINCESS_H


#include"block.h"

class Princess : public Block
{
public:
    Princess();
    bool action(Hero*hero);
private:
    QDialog*pri;
};

#endif // PRINCESS_H
