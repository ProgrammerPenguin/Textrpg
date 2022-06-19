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
			"���� ���� ����\n\n"
			"��� : ��� ����?\n\n"
			"1. ����\n"
			"2. ���尣(�̱���)\n"
			"3. CocaCola\n"
			"4. ����\n\n\n\n"
			"0. ĳ���� ����\n";
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
			cout << "�ٽ� �����غ���";
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
		"����\n\n"
		"2^1 : �ƹ��ų� ��󺸶��~ �ΰ� �ٰ�\n\n"
		"1. HP���� : " << HPCOST << "\n"
		"2. MP���� : " << MPCOST << "\n"
		"3. ������ ���ư���.\n";
	switch (Input_Key())
	{
	case '1':
		if (Penguin.GetGold() > HPCOST)
		{
			Penguin.SetGold(Penguin.GetGold() - HPCOST);
			++HPcount;
			cout << "ü�� ������ �����߽��ϴ�\n"
				"���� ü�� ������ " << HPcount << "�Դϴ�\n";
		}
		else
		{
			cout << 
				"���� �����ϴ�\n\n"
				"2^1 : �� ����? NAGA\n";
			Input_Key();
			RESET
			Village();
		}
		cout << "�ٽ� ���Ÿ� ���Ͻø� �ƹ� Ű�� �����ּ���\n";
		Input_Key();
		RESET
		Shop();
		break;
	case '2':
		if (Penguin.GetGold() > MPCOST)
		{
			Penguin.SetGold(Penguin.GetGold() - MPCOST);
			++MPcount;
			cout << "���� ������ �����߽��ϴ�\n"
				"���� ���� ������ " << MPcount << "�Դϴ�\n";
		}
		else
		{
			cout <<
				"���� �����ϴ�\n\n"
				"2^1 : �� ����? NAGA\n";
			Input_Key();
			RESET
			Village();
		}
		cout << "�ٽ� ���Ÿ� ���Ͻø� �ƹ� Ű�� �����ּ���\n";
		Input_Key();
		RESET
		Shop();
		break;
	case '3':
		RESET;
		Village();
		break;
	default:
		cout << "�ٽ� �����غ���";
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
		"���尣\n\n"
		"����� : ������ ���尣����\n\n"
		"1. ���� : " << "\n"
		"2. �� : " << "\n"
		"3. ������ ���ư���.\n";
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
		cout << "�ٽ� �����غ���";
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
		"��0�� : 00111111001111110011111100111111\n"
		"1. �ݶ� �����Ѵ�.\n"
		"2. ������ ���ư���.\n";
	switch (Input_Key())
	{
	case '1':
		if (Penguin.GetGold() >= COCACOLACOST && !isCocaCola)
		{
			Penguin.SetGold(Penguin.GetGold() - COCACOLACOST);
			isCocaCola = true;
			cout << "CocaCola�� �����߽��ϴ�\n\n"
				"��0�� : 0011111100111111\n";
		}
		else if (Penguin.GetGold() >= COCACOLACOST && isCocaCola)
		{
			cout <<
				"��ī�ݶ� �̹� �ֽ��ϴ�.\n\n"
				"��0�� : 00111111001111110011111100111111\n";
		}
		else if (Penguin.GetGold() < COCACOLACOST)
		{
			cout << "���� �����ϴ�.\n\n"
				"��0�� : 001111110011111100111111\n";
		}
		cout << "������ ���ư����� �ƹ� Ű�� �����ּ���\n";
		Input_Key();
		RESET
		Village();
		break;
	case '2':
		RESET;
		Village();
		break;
	default:
		cout << "�ٽ� �����غ���";
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
		"1. ���� ���\n"
		"2. ���� ȣ��\n"
		"3. ���� ����\n"
		"4. ���� ����\n"
		"������ ������ ����ּ���.\n\n\n"
		"5. ������ ���ư���.\n";
	switch (Input_Key())
	{
	case '1':
		stage.Dunguen("���� ���", 5, isclaer1);
			
		break;
	case '2':
		if (isclaer1)
		{
			stage.Dunguen("���� ȣ��", 10, isclaer2);
		}
		else
		{
			cout << "���� ��� ���縦 �Ϸ� �� ���� �Ͻ� �� �ֽ��ϴ�.\n";
			Input_Key();
			RESET
			Dunguen();
		}
		break;
	case '3':
		if (isclaer2)
		{
			stage.Dunguen("���� ����", 15, isclaer3);
		}
		else
		{
			cout << "���� ȣ�� ���縦 �Ϸ� �� ���� �Ͻ� �� �ֽ��ϴ�.\n";
			Input_Key();
			RESET
			Dunguen();
		}
		break;
	case '4':
		if (isclaer3)
		{
			stage.Dunguen("���� ����", 20, isclaer4);
		}
		else
		{
			cout << "���� ���� ���縦 �Ϸ� �� ���� �Ͻ� �� �ֽ��ϴ�.\n";
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
		cout << "�ٽ� �Է����ֽʽÿ�";
		Sleep(100);
		RESET
		break;
	}

	
}
