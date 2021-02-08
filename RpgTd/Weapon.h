#ifndef ARME_H
#define ARME_H
#pragma once
	
using namespace std;

#include <string>
#include <iostream>

class Weapon
{
	int id;
	string name;
	int damage;
	int range;

	public:

		Weapon(string name, int damage, int range);

		int getId();
		void setId(int id);

		string getName();

		void setDamage(int damage);
		int getDamage();
		void setRange(int range);
		int getRange();


		~Weapon();

};
#endif