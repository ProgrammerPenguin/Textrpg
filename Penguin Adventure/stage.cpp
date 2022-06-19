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
				"���̴�.\n"
				"1. �����Ѵ�.\n"
				"2. �������� ����Ѵ�.\n"
				"3. ������ ���ư���.\n\n\n"
				"0. ĳ���� ����";
			
			switch (Input_Key())
			{
			case '0':
				RESET
				Penguin.Info();
				cout << "���ư����� �ƹ�Ű�� �Է����ּ���.\n";
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
				cout << "�ٽ� �Է����ֽʽÿ�";
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
			else // �� �ȵ���?
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
	case 1: Fox.SetMonster("�ϱ� ����", 300, 30, 200);
		cout << Fox.GetName() << "�� �����ƴ�.\n"
			"��� : �Ϳ��� ������ ������!!\n";
		Input_Key();
		RESET
		while(Penguin.GetNowHp() > 0 && Fox.GetNowHp() > 0)
		{
			Choice(stagesize, &Fox);
		}
		break;
	case 2: Seal.SetMonster("�ϱ� ����", 300, 30, 200);
		cout << Seal.GetName() << "�� �����ƴ�.\n"
			"��� : ��ó�� ���Ƽ� ����ó�� ���!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && Seal.GetNowHp() > 0)
		{
			Choice(stagesize,&Seal);
		}
		break;
	case 3: Wolf.SetMonster("�ϱ� ����", 300, 30, 200);
		cout << Wolf.GetName() << "�� �����ƴ�.\n"
			"��� : �� �̹� �׾��ִ�.\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && Wolf.GetNowHp() > 0)
		{
			Choice(stagesize, &Wolf);
		}
		break;
	case 4: PolorBear.SetMonster("�ϱ� ��", 300, 30, 200);
		cout << PolorBear.GetName() << "�� �����ƴ�.\n"
			"��� : ���� ����� ���ư�!!\n";
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
	case 1: CaptainFox.SetMonster("���� �ϱ� ����", 300, 30, 200);
		cout << CaptainFox.GetName() << "�� �����ƴ�.\n"
			"��� : ���� ���嵵 �Ϳ���!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainFox.GetNowHp() > 0)
		{
			Choice(stagesize, &CaptainFox);
		}
		isclaer1 = true;
		break;
	case 2: CaptainSeal.SetMonster("���� �ϱ� ����", 300, 30, 200);
		cout << CaptainSeal.GetName() << "�� �����ƴ�.\n"
			"��� : ���ó�� ���Ƽ� !!!!\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainSeal.GetNowHp() > 0)
		{
			Choice(stagesize, &CaptainSeal);
		}
		isclaer2 = true;
		break;
	case 3: CaptainWolf.SetMonster("���� �ϱ� ����", 300, 30, 200);
		cout << CaptainWolf.GetName() << "�� �����ƴ�.\n"
			"��� : �������� �� �ŵ��̷�.\n";
		Input_Key();
		RESET
		while (Penguin.GetNowHp() > 0 && CaptainWolf.GetNowHp() > 0)
		{
			Choice(stagesize,&CaptainWolf);
		}
		isclaer3 = true;
		break;
	case 4: CaptainPolorBear.SetMonster("���󺣾�", 300, 30, 200);
		cout << CaptainPolorBear.GetName() << "�� �����ƴ�.\n"
			"��� : ���� ������ ���İ� ���� ����.\n";
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
		"1. HP���� : " << HPcount << "\n"
		"2. MP���� : " << MPcount << "\n"
		"���ư����� �ƹ� Ű�� ��������.\n";
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
			cout << "��� : ü���� ȸ���� ü���� " << Penguin.GetNowHp() << "�ƴ�.\n";
			HPcount--;
			Input_Key();
			break;
		}
		else
		{
			cout << "ü�� ������ �������Ű���.\n"
				"������ ���ư��°� ���ڴ�.\n";
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
			cout << "��� : ������ ȸ���� ������ " << Penguin.GetNowMp() << "�ƴ�.\n";
			MPcount--;
			Input_Key();
			break;
		}
		else
		{
			cout << "���� ������ �������Ű���.\n"
				"������ ���ư��°� ���ڴ�.\n";
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
	cout << "���� �ൿ�� ���� �ϼ���\n"
		"1. �Ϲ� ���� : " << Penguin.GetAtk() << "\n" <<
		"2. ��ų : " << Penguin.GetSkillName() << " : " << Penguin.GetSkillDamage() << "\n" <<
		"3. ������ ����Ѵ�.\n"
		"4. �ݶ� ������\n";
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
				cout << "��ī�ݶ� ������ �� ƴ�� �����ƴ�.\n";
				Input_Key();
				RESET
				Village();
				break;
			}
			else
			{
				cout << "�ݶ� ����.\n"
					"�ٸ� ����� �����غ���\n";
				Input_Key();
				RESET
				isChoice = true;
				Choice(stagesize, monster);
				break;
			}
		default:
			cout << "\n";
			cout << "�ٽ� �Է����ֽʽÿ�";
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
	cout << "�ش� : ��翩 ��ſ��� �ູ��.\n\n"
		"ü�°� ������ ��� ȸ���Ǿ���!\n";
	Penguin.SetNowHp(Penguin.GetMaxHp());
	Penguin.SetNowMp(Penguin.GetMaxMp());
	Input_Key();
}

void Stage::Box()
{
	cout << "���� ����ִ� ���ڸ� �־���.\n";
	int gold = 10 * (rand() % 50);
	Penguin.SetGold(Penguin.GetGold() + gold);
	cout << gold << "�� ��� ��尡 " << Penguin.GetGold() << "�Ǿ���!\n";
	Input_Key();
}
