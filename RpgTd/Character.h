#ifndef PERSO_H
#define PERSO_H
#pragma once

#include "Weapon.h" 
#include <list>
#include <vector>


class Character  
{	
protected :

	string className = "None";
	vector<int> position{ 0, 0 };
	int strength; // force
	bool alive = true; // vivant ?
	string RIP; // Nom perso
	string pain; // Nom perso
	string death; // Nom perso
	string name; // Nom perso
	int hp; // PV courant
	int physicalRes = 0; // PV max
	int magicalRes = 0; // PV courant
	int hpMax; // PV max
	list<Weapon*> weapons;
	Weapon* m_weapon;

public:

		Character(string name, int hp, int strength,Weapon* m_weapon, vector<int> pos);
		Character();

		string getClassName();
		void setClassName(string className);

		string getName();
		void setName(string name);

		void setHealth(int hp);
		int getHealth();

		int getHealthMax();
		void setHealthMax(int health);

		void setStrength(int strength);
		int getStrength();

		void setAlive(bool alive);
		bool getAlive();

		void setPhysicalRes(int res);
		int getPhysicalRes();

		void setMagicalRes(int res);
		int getMagicalRes();

		void move(int x, int y);
		void setPosition(vector<int> pos);
		vector<int> getPosition();

		virtual void addHealth(int potion);
		virtual void removeHealth(int damage);

		virtual int attack(Character* target);

		int addWeapon(string name, int damage, int range);
		int addWeapon(Weapon* weapon);

		void removeWeapon(Weapon* weapon);
		void removeWeapon(int id);

		void changeWeapon(string name);
		void changeWeapon(int id);

		virtual ~Character();

		virtual void displayInfo();

protected :

		void die();

};
#endif