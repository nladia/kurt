#ifndef ROOM_H
#define ROOM_H
#include "Pers.h"
#include "monster.h"
#include "ability.h"

class Room
{
    int num;
    int atkp;
    int atkm;
    int rol;
public:
    bool alive;
    Pers *pers;
    Ability *ability;
    Monster *monstr;
    Room();
    Room(int, Pers*, int, Ability*);
    ~Room ();
    int battle();
    int attkp();
    int attkm();
    int roll();
};

#endif // ROOM_H
