#include "main.h"

bool isVillage = false;
extern Player Penguin;
extern Stage stage;

void Village()
{
	while (!isVillage)
	{
		isVillage = true;
		cout <<
			"남극 얼음 마을\n\n"
			"펭귄 : 어디를 갈까?\n\n"
			"1. 상점\n"
			"2. 대장간(미구현)\n"
			"3. CocaCola\n"
			"4. 모험\n\n\n\n"
			"0. 캐릭터 정보\n";
		switch (Input_Key())
		{
		case '0':
			Penguin.Info();
			isVillage = false;
			Input_Key();
			RESET
			Village();
			break;
		case '1':
			//isVillage = true;
			RESET
			Shop();
			break;
		case '2':
			//isVillage = true;
			RESET
			Blacksmith();
			break;
		case '3':
			//isVillage = true;
			RESET
			CocaCola();
			break;
		case '4':
			//isVillage = true;
			RESET
			Dunguen();
			break;
		default:
			cout << "다시 생각해보자";
			isVillage = false;
			Sleep(100);
			system("cls");
			break;
		}
	}

}

extern int HPcount;
extern int MPcount;
void Shop()
{
	isVillage = false;
	cout <<
		"상점\n\n"
		"2^1 : 아무거나 골라보라고~ 싸게 줄게\n\n"
		"1. HP물약 : " << HPCOST << "\n"
		"2. MP물약 : " << MPCOST << "\n"
		"3. 마을로 돌아간다.\n";
	switch (Input_Key())
	{
	case '1':
		if (Penguin.GetGold() > HPCOST)
		{
			Penguin.SetGold(Penguin.GetGold() - HPCOST);
			++HPcount;
			cout << "체력 물약을 구매했습니다\n"
				"현재 체력 물약은 " << HPcount << "입니다\n";
		}
		else
		{
			cout << 
				"돈이 없습니다\n\n"
				"2^1 : 돈 없어? NAGA\n";
			Input_Key();
			RESET
			Village();
		}
		cout << "다시 구매를 원하시면 아무 키나 눌러주세요\n";
		Input_Key();
		RESET
		Shop();
		break;
	case '2':
		if (Penguin.GetGold() > MPCOST)
		{
			Penguin.SetGold(Penguin.GetGold() - MPCOST);
			++MPcount;
			cout << "마나 물약을 구매했습니다\n"
				"현재 마나 물약은 " << MPcount << "입니다\n";
		}
		else
		{
			cout <<
				"돈이 없습니다\n\n"
				"2^1 : 돈 없어? NAGA\n";
			Input_Key();
			RESET
			Village();
		}
		cout << "다시 구매를 원하시면 아무 키나 눌러주세요\n";
		Input_Key();
		RESET
		Shop();
		break;
	case '3':
		RESET;
		Village();
		break;
	default:
		cout << "다시 생각해보자";
		Sleep(200);
		RESET
		Shop();
		break;
	}
}

void Blacksmith()
{
	isVillage = false;
	cout <<
		"대장간\n\n"
		"김잼민 : 진실의 대장간으로\n\n"
		"1. 무기 : " << "\n"
		"2. 방어구 : " << "\n"
		"3. 마을로 돌아간다.\n";
	switch (Input_Key())
	{
	case '1':
		RESET;
		Village();
		break;
	case '2':
		RESET;
		Village();
		break;
	case '3':
		RESET;
		Village();
		break;
	default:
		cout << "다시 생각해보자";
		Sleep(200);
		RESET
			Shop();
		break;
	}
}

bool isCocaCola = true;

void CocaCola()
{
	isVillage = false;
	cout << "CocaCola\n"
		"김0훈 : 00111111001111110011111100111111\n"
		"1. 콜라를 보충한다.\n"
		"2. 마을로 돌아간다.\n";
	switch (Input_Key())
	{
	case '1':
		if (Penguin.GetGold() >= COCACOLACOST && !isCocaCola)
		{
			Penguin.SetGold(Penguin.GetGold() - COCACOLACOST);
			isCocaCola = true;
			cout << "CocaCola를 구매했습니다\n\n"
				"김0훈 : 0011111100111111\n";
		}
		else if (Penguin.GetGold() >= COCACOLACOST && isCocaCola)
		{
			cout <<
				"코카콜라가 이미 있습니다.\n\n"
				"김0훈 : 00111111001111110011111100111111\n";
		}
		else if (Penguin.GetGold() < COCACOLACOST)
		{
			cout << "돈이 없습니다.\n\n"
				"김0훈 : 001111110011111100111111\n";
		}
		cout << "마을로 돌아가려면 아무 키나 눌러주세요\n";
		Input_Key();
		RESET
		Village();
		break;
	case '2':
		RESET;
		Village();
		break;
	default:
		cout << "다시 생각해보자";
		Sleep(200);
		RESET
		CocaCola();
		break;
	}
}

bool isclaer1 = false;
bool isclaer2 = false;
bool isclaer3 = false;
bool isclaer4 = false;

void Dunguen()
{
	isVillage = false;
	cout <<
		"1. 얼음 계곡\n"
		"2. 얼음 호수\n"
		"3. 얼음 동굴\n"
		"4. 얼음 빙산\n"
		"모험할 지역을 골라주세요.\n\n\n"
		"5. 마을로 돌아간다.\n";
	switch (Input_Key())
	{
	case '1':
		stage.Dunguen("얼음 계곡", 5, isclaer1);
			
		break;
	case '2':
		if (isclaer1)
		{
			stage.Dunguen("얼음 호수", 10, isclaer2);
		}
		else
		{
			cout << "얼음 계곡 조사를 완료 후 입장 하실 수 있습니다.\n";
			Input_Key();
			RESET
			Dunguen();
		}
		break;
	case '3':
		if (isclaer2)
		{
			stage.Dunguen("얼음 동굴", 15, isclaer3);
		}
		else
		{
			cout << "얼음 호수 조사를 완료 후 입장 하실 수 있습니다.\n";
			Input_Key();
			RESET
			Dunguen();
		}
		break;
	case '4':
		if (isclaer3)
		{
			stage.Dunguen("얼음 빙산", 20, isclaer4);
		}
		else
		{
			cout << "얼음 동굴 조사를 완료 후 입장 하실 수 있습니다.\n";
			Input_Key();
			RESET
			Dunguen();
		}
		break;
	case '5':
		RESET
		Village();

		break;
	default:
		cout << "\n";
		cout << "다시 입력해주십시오";
		Sleep(100);
		RESET
		break;
	}

	
}
