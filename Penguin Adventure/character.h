#pragma once

#include "header.h"

class Character
{
public:
	string _name;
	int _hp;
	int _mp;
	int _atk;
	int _def;

	Character(string name, int hp, int mp, int atk, int def)
	{
		_name = name;
		_hp = hp;
		_mp = mp;
		_atk = atk;
		_def = def;

	}
	
};

