#pragma once

class Item
{
public:
	Item(string Name, int Hp, int Mp, int Price, int count);

public:
	string _name;
	int _price;
	int _healhp;
	int _healmp;
	int _count;
};

class Equipment
{
public:
	//Equipment();
	//Equipment(string name, int atk, int price); // 무기
	//Equipment(string name, int hp, int price); // 방어구
	//Equipment(string name, int mp, int price); // 장신구
public:
	string _name;
	int _hp;
	int _mp;
	int _atk;
	int _price;
	Player _player;
};