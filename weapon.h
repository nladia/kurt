#ifndef WEAPON_H
#define WEAPON_H
#include <cstdlib>


class Weapon
{
    int minatk;
    int maxatk;
public:
    Weapon();
    void stndrt(int);
    Weapon(int, int);
    int weapdif();
    int weapmin();
};

#endif // WEAPON_H
