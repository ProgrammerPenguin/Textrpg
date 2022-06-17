#pragma once
#include "character.h"

class Monster :public Character
{
public:
	Monster(string name, int hp, int mp, int atk, int def) : Character (name, hp, mp, atk, def) {}
};

class PolorBear :public Monster
{
public:
    PolorBear() : Monster("合必磅", 30, 30, 30, 30)
    {
   /*     _name = "合必磅";
        _hp = 30;
        _mp = 30;
        _atk = 30;
        _def = 30;*/
    }
    //PolorBear(string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def)
  /*  {
        name = "合必磅";
        hp = 30;
        mp = 30;
        atk = 30;
        def = 30;
    }*/
    void Info();
    
};

    //    > 合必磅
    //> 合必拱俺
    //> 合必咯快
    //> 合必戳措