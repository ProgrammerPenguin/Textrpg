#pragma once

#include "main.h"

class Stage
{
public:
	void Dunguen(string name, int stagesize, bool isclear);
	void Battle(int stagesize);
	void Bossbattle(int stagesize);
	void Rest();
	void Box();


public:
	string _name = "No name";
	bool isclear = false;
	int stagesize = 0;
	
};
