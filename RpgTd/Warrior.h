#pragma once
#include "Character.h"

class Warrior : public virtual Character
{
	int regenValue; // regen value
public:
	Warrior(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int regenValue);
	Warrior();

	void setRegenValue(int value);
	int getRegenValue();
	void rotativeAttack();
	void displayInfo() override;

private:

	void regenerateHealth();
};

