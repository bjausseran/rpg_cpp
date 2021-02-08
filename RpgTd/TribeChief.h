#pragma once
#include "Character.h"

class Characters;


template <typename T>
class TribeChief : public T
{
public:
	TribeChief();
	void SendTribe(Character* target);

};

template <typename T>
inline TribeChief<typename T>::TribeChief()
{
	this->hpMax = this->hpMax * 2;
	this->hp = this->hpMax;
	this->strength = this->strength * 2;
}

template <typename T>
void TribeChief<typename T>::SendTribe(Character* target)
{
	cout << "+----------------------------------------+" << endl;
	cout << "| " << this->name << ", the " << this->className << " Lord, is going full tribe !!" << endl;
	cout << "+             --------------" << endl;
	list<Character*> chars = Characters::getInstance()->getList();
	for (list<Character*>::iterator it = chars.begin(); it != chars.end(); ++it)
	{
		if ((*it)->getClassName() == this->className && (*it)->getAlive())
		{
			(*it)->attack(target);
		}
	}
}