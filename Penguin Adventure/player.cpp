#include "player.h"

void Player::Info()
{
	cout << "Name      : " << _name << "\n";
	cout << "Hp        : " << _hp << "\n";
	cout << "Mp        : " << _mp << "\n";
	cout << "atk       : " << _atk << "\n";
	cout << "def       : " << _def << "\n";
	cout << "skill     : " << _skill_name << "\n";
	cout << "skill dmg : " << _skill_damage << "\n";
	cout << "skill mp  : " << _skill_usemp << "\n";

}