#include "main.h"
#include "village.h"

Player Penguin;
Stage stage;

int Input_Key()
{
	int temp = _getch();
	
	return temp;
}

char* Enter_Key()
{
	char temp;
	cin >> temp;

	return &temp;
}

int HPcount = 0;
int MPcount = 0;
int main()
{
	srand(time(NULL));
	
	PlaySound(TEXT("bgm.wav"), NULL, SND_ASYNC | SND_LOOP);

	system("mode con cols=120 lines=60");
	Title();

	system("mode con cols=150 lines=40");
	Intro();

	Village();
	
}