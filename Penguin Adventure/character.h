#pragma once

#include "main.h"

class Character
{
private:

public:
	string _name;
	int _maxhp;
	int _nowhp;
	int _atk;
	int _gold;
public:
	Character();
	Character(string name, int hp, int atk, int gold);

	string GetName();
	int GetMaxHp();
	int GetNowHp();
	int GetAtk();
	int GetGold();

	void SetName(string& name);
	void SetMaxHp(int maxhp);
	void SetNowHp(int hp);
	void SetAtk(int atk);
	void SetGold(int gold);
};


class Player :public Character
{
public:
	Player();
	Player(int maxMp, int mp, string skill_name, int skill_damage, int skill_usemp);

	int GetMaxMp();
	int GetNowMp();
	string GetSkillName();
	int GetSkillDamage();
	int GetSkillUseMp();

	void SetMaxMp(int maxmp);
	void SetNowMp(int mp);
	void SetSkillName(string skill_name);
	void SetSkillDamage(int skill_damage);
	void SetSkillUseMp(int skill_usemp);

	void Info();
	void Attak(Monster* monster);
	void SkillAttak(Monster* monster);
	void Youdie();

public:
	int _maxmp = 100;
	int _nowmp = 100;
	string _skill_name;
	int _skill_damage = 100;
	int _skill_usemp = 150;

};

class Monster :public Character
{
public:
	Monster();
	Monster(string name, int maxhp, int atk, int gold);

	void SetMonster(string name, int maxhp, int atk, int gold);
	void Attak(Player* player);
	void Info();
};

