#include "monster.h"

Monster::Monster()
{

}

Monster::Monster(int y, int x)
{
    if (y == 1)
    {
        hp = 45;
        minatk = 6;
        maxatk = 8;
        exp = 12;
    }
    if (y == 2)
    {
        hp = 50;
        minatk = 10;
        maxatk = 13;
        exp = 13;
    }
    if (y == 3)
    {
        hp = 40;
        minatk = 13;
        maxatk = 14;
        exp = 14;
    }
    hp += 52 * x;
    minatk += 8 * x;
    maxatk += 9 * x;
    exp += 2*x;

}

int Monster::attack()
{
    return rand()%(maxatk - minatk) + minatk;
}
void Monster::dmg(int x)
{
    hp-=x;
}

int Monster::hpp()
{
    return hp;
}

int Monster::gexp()
{
    return exp;
}

int Monster::maxattk()
{
    return maxatk;
}

int Monster::minattk()
{
    return minatk;
}
