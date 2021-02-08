#pragma once
#include "Berserk.h"
#include "Mage.h"

class Shaman :
    public Berserk, public Mage
{
	int healValue; // heal value
	int fireballDamage = 60; // firaball damage
	bool inBerserk = false;
	bool hadBerserk = false;
	string berserkSentence = "Gnagni ?";

public:
	Shaman(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int healValue, int regenValue);
	Shaman();

	void displayInfo() override; 
	int attack(Character* target);


private:
	void GetInBerserk(bool value);
};

