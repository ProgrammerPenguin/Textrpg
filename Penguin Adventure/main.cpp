#include "main.h"
#include "village.h"
/// <summary>
/// 장비하고 장비에 스킬을 넣어 구현하려고했으나 못했습니다.
/// 그로 인해 밸런스도 완벽하게 맞추지 못했습니다.
/// 구동잘되기 확인하기 위해 체력을 무한에 가깝게 설정했습니다.
/// </summary>
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