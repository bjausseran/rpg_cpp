#include "Weapon.h"  
	
Weapon::Weapon(string name, int damage, int range)
{
	this->id = -1;
	this->name = name;
    this->damage = damage;
	this->range = range;
}

int Weapon::getId()
{
	return id;
}

void Weapon::setId(int id)
{
	this->id = id;
}

string Weapon::getName()
{
	return this->name;
}

void Weapon::setDamage(int damages)
{
	this->damage = damages;
}

int Weapon::getDamage()
{
	return this->damage;
}

void Weapon::setRange(int range)
{
	this->range = range;
}

int Weapon::getRange()
{
	return range;
}

Weapon::~Weapon()
{
	cout << "~ " << name << " burried for later." << endl;
}