#include "weapon.h"

Weapon::Weapon()
{

}

void Weapon::stndrt(int x)
{
    if (x==1)
    {
        minatk = 2;
        maxatk = 3;
    }
    if (x==2)
    {
        minatk = 2;
        maxatk = 4;
    }
    if (x==3)
    {
        minatk = 1;
        maxatk = 4;
    }
}
Weapon::Weapon(int x, int y)
{
    if (y == 0) y = 1;
    if (x==1)
    {
        minatk = rand()%(y+1);
        maxatk = rand()%(y+3);
    }
    if (x==2)
    {
        minatk = rand()%(y+2);
        maxatk = rand()%(y+4);}
    if (x==3)
    {
        minatk = rand()%(y);
        maxatk = rand()%(y+4);
    }
    if(minatk >= maxatk) maxatk = minatk + 1;
}

int Weapon::weapmin()
{
    return minatk;
}

int Weapon::weapdif()
{
    return maxatk - minatk;
}

