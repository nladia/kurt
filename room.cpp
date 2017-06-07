#include "room.h"

Room::Room()
{

}

Room::Room(int x, Pers *h, int floor, Ability *abil)
{
    ability = abil;
    pers = h;
    num = x;
    alive = true;
    monstr = new Monster(x, floor);
}

int Room::battle()
{
    double mdmg = 1,pdmg = 1;
    int modw = 0, modr = 0, moda1 = 1, moda2 = 1;
    int f = rand()%(11)+1;
    rol = f;
    switch(f)
    {
    case 1:{mdmg =1.5 ;pdmg = 0 ; break;}
    case 2:{mdmg =1.5 ;pdmg = 0.6; break;}
    case 3:{mdmg = 0.8;pdmg = 0 ; break;}
    case 4:{mdmg = 1;pdmg = 0.8; break;}
    case 5:{mdmg = 0.8;pdmg = 0.6; break;}
    case 6:{mdmg = 1;pdmg = 1; break;}
    case 7:{mdmg = 0.8;pdmg = 0.8; break;}
    case 8:{mdmg = 0.6;pdmg = 0.8; break;}
    case 9:{mdmg = 0.6;pdmg = 1; break;}
    case 10:{mdmg = 0;pdmg = 1; break;}
    case 11:{mdmg = 0.6;pdmg =1.5; break;}
    case 12:{mdmg = 0;pdmg = 1.5; break;}
    }

    f = rand()%(7);

    switch(pers->gcls())
    {
    case 1:
    {
        switch(f)
        {
            case 1: {modw = 5 + 3 * pers->levl(); break;}
            case 2: {modw = 5 + 3 * pers->levl(); break;}
        }
        break;
    }
    case 2:
    {
        switch(f)
        {
            case 1: {modr = 5 + pers->levl(); break;}
            case 2: {modr = 5 + pers->levl(); break;}
        }
        break;
    }
    case 3:
    {
        switch(f)
        {
            case 1: {moda1 = 0; break;}
            case 2: {moda2 = 1.2; break;}
        }
        break;
    }
    }



   mdmg = monstr->attack() * mdmg;
   pdmg = pers->attack() * pdmg;

   mdmg = (mdmg - modw) * moda1;
   pdmg = (pdmg + modr) * moda2;

    int mdmgs = mdmg, pdmgs = pdmg;

    ability->battle(pers,monstr,&pdmgs,&mdmgs);

   if (mdmgs < 0)
       mdmgs = 0;
   if (pdmgs < 0)
       pdmgs = 0;

   atkm = mdmgs;
   atkp = pdmgs;


   pers->dmg(mdmgs);
   monstr->dmg(pdmgs);

   if (pers->hpp() <=0)
       return -1;

   if (monstr->hpp() <=0)
   {
       alive = false;
       return 1;
   }

   return 0;
}

int Room::attkm()
{
    return atkm;
}

int Room::attkp()
{
    return atkp;
}

int Room::roll()
{
    return rol;
}

Room::~Room()
{
    delete monstr;
}

