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
    PolorBear() : Monster("�ϱذ�", 30, 30, 30, 30)
    {
   /*     _name = "�ϱذ�";
        _hp = 30;
        _mp = 30;
        _atk = 30;
        _def = 30;*/
    }
    //PolorBear(string name, int hp, int mp, int atk, int def) : Monster(name, hp, mp, atk, def)
  /*  {
        name = "�ϱذ�";
        hp = 30;
        mp = 30;
        atk = 30;
        def = 30;
    }*/
    void Info();
    
};

    //    > �ϱذ�
    //> �ϱع���
    //> �ϱؿ���
    //> �ϱش���