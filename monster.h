#ifndef MONSTER_H
#define MONSTER_H
#include <cstdlib>


class Monster
{
    int hp;
    int minatk;
    int maxatk;
    int exp;
public:
    Monster();
    Monster(int, int);
    int attack();
    void dmg(int);
    int hpp();
    int gexp();
    int minattk();
    int maxattk();
};

#endif // MONSTER_H
