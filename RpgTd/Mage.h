#pragma once
#include "Character.h"

class Mage :
    public virtual Character
{
	int healValue; // heal value
	int fireballDamage = 60; // firaball damage

public:
	Mage(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int healValue);
	Mage();

	void heal(Character* perso);
	void throwFireball(Character* perso);

	void setHealValue(int value);
	int getHealValue();
	void displayInfo() override;
};

