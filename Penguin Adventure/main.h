#pragma once
 
#include <iostream>
#include <conio.h>	
#include <windows.h>
#include <ctime>
#include <cstdlib>	

#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>
using namespace std;

class Character;
class player;
class Monster;


#include "scene.h"
#include "character.h"
#include "item.h"
#include "stage.h"
#include "village.h"

#define ENTER 13
#define RESET system("cls");
#define HPHEAL 50
#define MPHEAL 50
#define HPCOST 300
#define MPCOST 300
#define COCACOLACOST 300
int Input_Key();
char* Enter_Key();

