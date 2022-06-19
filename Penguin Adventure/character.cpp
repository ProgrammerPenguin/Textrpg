#include "main.h"


extern Player Penguin;
/// <summary>
/// Character 함수
/// </summary>
Character::Character() : _name("펭귄"), _maxhp(100000),_nowhp(100), _atk(100), _gold(1000)
{

}

Character::Character(string name, int hp, int atk, int gold) : _name(name), _maxhp(hp),_nowhp(hp), _atk(atk), _gold(gold)
{

}
// Get 함수
string Character::GetName()
{
	return _name;
}

int Character::GetMaxHp()
{
	return _maxhp;
}

int Character::GetNowHp()
{
	return _nowhp;
}

int Character::GetAtk()
{
	return _atk;
}

int Character::GetGold()
{
	return _gold;
}

// Set 함수
void Character::SetName(string& name)
{
	_name = name;
}
void Character::SetMaxHp(int maxhp)
{
	_maxhp = maxhp;
}

void Character::SetNowHp(int hp)
{
	_nowhp = hp;
}

void Character::SetAtk(int atk)
{
	_atk = atk;
}

void Character::SetGold(int gold)
{
	_gold  = gold;
}



/// <summary>
/// player 함수
/// </summary>
Player::Player() : _maxmp(100), _nowmp(100), _skill_name("마구때리기"), _skill_damage(150), _skill_usemp(50),Character()
{
	_name = "펭귄";
	_maxhp= 30000;
	_nowhp= 30000;
	_atk = 100;
	_gold= 1000;
}

Player::Player(int maxMp, int mp, string skill_name, int skill_damage, int skill_usemp) : _maxmp(maxMp), _nowmp(mp), _skill_name(skill_name), _skill_damage(skill_damage), _skill_usemp(skill_usemp)
{

}


// player 추가 Get 함수
int Player::GetMaxMp()
{
	return _maxmp;
}

int Player::GetNowMp()
{
	return _nowmp;
}

string Player::GetSkillName()
{
	return _skill_name;
}

int Player::GetSkillDamage()
{
	return _skill_damage;
}

int Player::GetSkillUseMp()
{
	return _skill_usemp;
}

// player 추가 Set 함수

void Player::SetMaxMp(int maxMp)
{
	_maxmp = maxMp;
}

void Player::SetNowMp(int mp)
{
	_nowmp = mp;
}

void Player::SetSkillName(string skill_name)
{
	_skill_name = skill_name;
}

void Player::SetSkillDamage(int skill_damage)
{
	_skill_damage = skill_damage;
}

void Player::SetSkillUseMp(int skill_usemp)
{
	_skill_usemp = skill_usemp;
}


extern int HPcount;
extern int MPcount;
extern bool isCocaCola;
void Player::Info()
{
	cout << "===========================\n";
	cout << "Name      : " << _name << "\n";
	cout << "Hp        : " << _nowhp << " / " << _maxhp << "\n";
	cout << "Mp        : " << _nowmp << " / " << _maxmp << "\n";
	cout << "atk       : " << _atk << "\n";
	cout << "skill     : " << _skill_name << "\n";
	cout << "skill dmg : " << _skill_damage << "\n";
	cout << "skill mp  : " << _skill_usemp << "\n";
	cout << "HP potion : " << HPcount << "\n";
	cout << "MP potion : " << MPcount << "\n";
	cout << "CocaCola  : " << isCocaCola << "\n";
	cout << "gold      : " << _gold << "\n";
	cout << "===========================\n";
}

void Player::Attak(Monster* monster)
{
	int Atk = GetAtk();
	int damage = Atk;
	
	if ((monster->GetNowHp() - damage) <= 0)
	{
		monster->SetNowHp(0);
		cout << monster->GetName() << "을(를) 처치했습니다.\n";
		Penguin.SetGold(monster->GetGold() + Penguin.GetGold());
		
		
	}
	else
	{
		monster->SetNowHp(monster->GetNowHp() - damage);
		cout << monster->GetName() << "은(는) " << damage << "의 피해를 입었다!\n";
	}
}
void Player::SkillAttak(Monster* monster)
{
	int Atk = GetSkillDamage();
	int damage = Atk;

	if (GetNowMp() < GetSkillUseMp())
	{
		cout << "마나가 부족합니다.\n";
	}
	else if ((monster->GetNowHp() - damage) <= 0)
	{
		SetNowMp(GetNowMp() - GetSkillUseMp());
		monster->SetNowHp(0);
		cout << monster->GetName() << "을(를) 처치했습니다.\n";
		Penguin.SetGold(monster->GetGold() + Penguin.GetGold());
	}
	else
	{
		SetNowMp(GetNowMp() - GetSkillUseMp());
		monster->SetNowHp(monster->GetNowHp() - damage);
		cout << monster->GetName() << "은(는) " << damage << "의 피해를 입었다!\n";
	}
}

void Player::Youdie()
{
	
}

/// <summary>
/// Monster 함수
/// </summary>
Monster::Monster() : Character()
{

}
Monster::Monster(string name, int maxhp, int atk, int gold) : Character(name, maxhp, atk, gold)
{

}

void Monster::SetMonster(string name, int maxhp, int atk, int gold)
{
	SetName(name);
	SetMaxHp(maxhp);
	SetNowHp(maxhp);
	SetAtk(atk);
	SetGold(gold);
}

void Monster::Attak(Player* player)
{
	int Atk = GetAtk();
	int damage = Atk;
	bool isrestart = false;
	if ((player->GetNowHp() - damage) <= 0)
	{
		cout << "YOU DIED\n";
		Input_Key();
		return exit(NULL);
		//while (!isrestart)
		//{
		//	cout <<
		//		"다시 하시겠습니까?\n"
		//		"1. YES 2. No\n";
		//	switch (Input_Key())
		//	{
		//	case '1':
		//		RESET
		//		isrestart = true;
		//		Title();
		//		break;
		//	case '2':
		//		return exit(NULL);
		//	default:
		//		cout << "\n";
		//		cout << "다시 입력해주십시오";
		//		Sleep(100);
		//		RESET
		//			break;
		//	}

		//}
	}
	else
	{
		player->SetNowHp(player->GetNowHp() - damage);
		cout << player->GetName() << "은" << damage << "의 피해를 입었다!\n";
		if (player->GetNowHp() < (player->GetMaxHp() / 20))
		{
			cout <<
				"체력이 없습니다\n"
				"물약을 사용하거나 콜라를 이용하세요!\n";
		}
	}
}

void Monster::Info()
{
	cout << "===========================\n";
	cout << "Name      : " << GetName() << "\n";
	cout << "Hp        : " << GetNowHp() << " / " << GetMaxHp() << "\n";
	cout << "atk       : " << GetAtk() << "\n";
	cout << "===========================\n";
}