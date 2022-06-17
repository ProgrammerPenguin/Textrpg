#pragma once

#include "character.h"

class Player :public Character
{
public:
	Player(string name, int hp, int mp, int atk, int def, string skill_name, int skill_damage, int skill_usemp) : Character(name, hp, mp, atk, def)
	{
		_skill_name = skill_name;
		_skill_damage = skill_damage;
		_skill_usemp = skill_usemp;
	}

	void Info();

public:
	string _skill_name;
	int _skill_damage;
	int _skill_usemp;

};