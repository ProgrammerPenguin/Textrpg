#include "main.h"

extern Player Penguin;
//extern bool isVillage;
void Useitem(int stagesize);
void Choice(int stagesize, Monster* monster);
extern bool isclaer1;
extern bool isclaer2;
extern bool isclaer3;
extern bool isclaer4;

void Stage::Dunguen(string name,int stagesize, bool isclear)
{
	
	for (int i = 1; i <= stagesize; ++i)
	{
		RESET
		bool isgo = false;
		while (!isgo)
		{
			cout << i <<
				"층이다.\n"
				"1. 전진한다.\n"
				"2. 아이템을 사용한다.\n"
				"3. 마을로 돌아간다.\n\n\n"
				"0. 캐릭터 정보";
			
			switch (Input_Key())
			{
			case '0':
				RESET
				Penguin.Info();
				cout << "돌아가려면 아무키나 입력해주세요.\n";
				Input_Key();
				RESET
				break;
			case '1':
				isgo = true;
				RESET
				break;
			case '2':
				Useitem(stagesize);
				RESET
				break;
			case '3':
				isgo = true;
				RESET
				Village();
				break;
			default:
				cout << "\n";
				cout << "다시 입력해주십시오";
				Sleep(300);
				RESET
				break;
			}

		}
		
		int stage = rand() % 100;
		if (i == stagesize)
		{
			Bossbattle(stagesize);
			
			RESET
			if (isclaer4)
			{
				End();
			}
			else // 왜 안되지?
			{
				isclear = 1;
				Village();
			}
		}
	
		if (stage >= 0 && stage < 40)
		{
			Battle(stagesize);
		}
		else if (stage >= 40 && stage < 60)
		{
			Rest();
		}
		else if (stage >= 60 && stage < 80)
		{
			Box();
		}
		else
		{
			continue;
		}
	}
}

void Stage::Battle(int stagesize)
{
	Monster Fox;
	Monster Seal;
	Monster Wolf;
	Monster PolorBear;
	int stage = stagesize / 5;
	switch (stage)
	{
	case 1: Fox.SetMonster("북극 여우", 300, 30, 200);
		cout << Fox.GetName() << "를 마주쳤다.\n"
			"펭귄 : 귀여운 여우녀셕 덤벼라!!\n";
		Input_Key();
		RESET
		while(Penguin.GetNowHp() > 0 && Fox.GetNowHp() > 0)
		{
			Choice(stagesize, &Fox);
		}
		break;
	case 2: Seal.SetMonster("북극 물개", 500, 50, 300);
		cout << Seal.GetName() << "를 마주쳤다.\n"
			"펭귄 : 벌처럼 날아서 나비처럼 찌르기!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && Seal.GetNowHp() > 0)
		{
			Choice(stagesize,&Seal);
		}
		break;
	case 3: Wolf.SetMonster("북극 늑대", 700, 70, 400);
		cout << Wolf.GetName() << "를 마주쳤다.\n"
			"펭귄 : 넌 이미 죽어있다.\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && Wolf.GetNowHp() > 0)
		{
			Choice(stagesize, &Wolf);
		}
		break;
	case 4: PolorBear.SetMonster("북극 곰", 900, 90, 600);
		cout << PolorBear.GetName() << "를 마주쳤다.\n"
			"펭귄 : 너희 나라로 돌아가!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && PolorBear.GetNowHp() > 0)
		{
			Choice(stagesize, &PolorBear);
		}
		break;
	default:
		break;
	}
}

void Stage::Bossbattle(int stagesize)
{
	Monster CaptainFox;
	Monster CaptainSeal;
	Monster CaptainWolf;
	Monster CaptainPolorBear;
	int stage = stagesize / 5;
	switch (stage)
	{
	case 1: CaptainFox.SetMonster("대장 북극 여우", 600, 60, 400);
		cout << CaptainFox.GetName() << "를 마주쳤다.\n"
			"펭귄 : 여우 대장도 귀여워!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainFox.GetNowHp() > 0)
		{
			Choice(stagesize, &CaptainFox);
		}
		isclaer1 = true;
		break;
	case 2: CaptainSeal.SetMonster("대장 북극 물개", 1000, 100, 600);
		cout << CaptainSeal.GetName() << "를 마주쳤다.\n"
			"펭귄 : 펭귄처럼 날아서 !!!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainSeal.GetNowHp() > 0)
		{
			Choice(stagesize, &CaptainSeal);
		}
		isclaer2 = true;
		break;
	case 3: CaptainWolf.SetMonster("대장 북극 늑대", 1200, 130, 1200);
		cout << CaptainWolf.GetName() << "를 마주쳤다.\n"
			"펭귄 : 오마에와 모 신데이루.\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainWolf.GetNowHp() > 0)
		{
			Choice(stagesize,&CaptainWolf);
		}
		isclaer3 = true;
		break;
	case 4: CaptainPolorBear.SetMonster("폴라베어", 2000, 200, 0);
		cout << CaptainPolorBear.GetName() << "를 마주쳤다.\n"
			"펭귄 : 어이 곰탱이 훔쳐간 보석 내놔.\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainPolorBear.GetNowHp() > 0)
		{
			Choice(stagesize,&CaptainPolorBear);
		}
		isclaer4 = true;
		break;
	default:
		break;
	}
}


extern int HPcount;
extern int MPcount;

void Useitem(int stagesize)
{
	int stage = stagesize / 5;
	RESET
	cout <<
		"1. HP물약 : " << HPcount << "\n"
		"2. MP물약 : " << MPcount << "\n"
		"돌아가려면 아무 키나 누르세요.\n";
	switch (Input_Key())
	{
	case '1':
		if (HPcount > 0)
		{
			Penguin.SetNowHp(Penguin.GetNowHp() + HPHEAL * stage * 10);
			if (Penguin.GetNowHp() > Penguin.GetMaxHp())
			{
				Penguin.SetNowHp(Penguin.GetMaxHp());
			}
			cout << "펭귄 : 체력을 회복해 체력이 " << Penguin.GetNowHp() << "됐다.\n";
			HPcount--;
			Input_Key();
			break;
		}
		else
		{
			cout << "체력 물약이 떨어진거같다.\n"
				"마을로 돌아가는게 좋겠다.\n";
			Input_Key();
			break;
		}
	case '2':
		if (MPcount > 0)
		{
			Penguin.SetNowMp(Penguin.GetNowMp() + MPHEAL * stage * 10);
			if (Penguin.GetNowMp() > Penguin.GetMaxMp())
			{
				Penguin.SetNowMp(Penguin.GetMaxMp());
			}
			cout << "펭귄 : 마나를 회복해 마나가 " << Penguin.GetNowMp() << "됐다.\n";
			MPcount--;
			Input_Key();
			break;
		}
		else
		{
			cout << "마나 물약이 떨어진거같다.\n"
				"마을로 돌아가는게 좋겠다.\n";
			Input_Key();
			break;
		}
	default:
		break;
	}
}

extern bool isCocaCola;

void Choice(int stagesize, Monster* monster)
{
	bool isChoice = false;
	RESET
	Penguin.Info();
	monster->Info();
	cout << "다음 행동을 선택 하세요\n"
		"1. 일반 공격 : " << Penguin.GetAtk() << "\n" <<
		"2. 스킬 : " << Penguin.GetSkillName() << " : " << Penguin.GetSkillDamage() << "\n" <<
		"3. 아이템 사용한다.\n"
		"4. 콜라를 던진다\n";
	while (!isChoice)
	{
		switch (Input_Key())
		{
		case '1':
			isChoice = true;
			Penguin.Attak(monster);
			monster->Attak(&Penguin);
			Input_Key();
			break;
		case '2':
			isChoice = true;
			Penguin.SkillAttak(monster);
			monster->Attak(&Penguin);
			Input_Key();
			break;
		case '3':
			Useitem(stagesize);
			RESET
			isChoice = true;
			Choice(stagesize, monster);
			break;
		case '4':
			if (isCocaCola)
			{
				isChoice = true;
				isCocaCola = false;
				cout << "코카콜라에 관심이 간 틈에 도망쳤다.\n";
				Input_Key();
				RESET
				Village();
				break;
			}
			else
			{
				cout << "콜라가 없다.\n"
					"다른 방법을 생각해보자\n";
				Input_Key();
				RESET
				isChoice = true;
				Choice(stagesize, monster);
				break;
			}
		default:
			cout << "\n";
			cout << "다시 입력해주십시오";
			Sleep(300);
			RESET
			isChoice = true;
			Choice(stagesize, monster);
			break;
		}
	}

}

void Stage::Rest()
{
	cout << "해달 : 용사여 당신에게 축복을.\n\n"
		"체력과 마나가 모두 회복되었다!\n";
	Penguin.SetNowHp(Penguin.GetMaxHp());
	Penguin.SetNowMp(Penguin.GetMaxMp());
	Input_Key();
}

void Stage::Box()
{
	cout << "돈이 들어있는 상자를 주었다.\n";
	int gold = 10 * (rand() % 50);
	Penguin.SetGold(Penguin.GetGold() + gold);
	cout << gold << "를 얻어 골드가 " << Penguin.GetGold() << "되었다!\n";
	Input_Key();
}
