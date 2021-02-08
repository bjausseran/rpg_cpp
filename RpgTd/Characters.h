#pragma once
#include <list>
#include "Character.h"
#include "Berserk.h"
#include "Warrior.h"
#include "Mage.h"
#include "Shaman.h"

class Characters
{
	static Characters* m_characters;
	list<Character*> players;

public :
	static Characters* getInstance();
	~Characters();


	virtual list<Character*> getList();
	virtual void addPlayer(Character* pers);
};

