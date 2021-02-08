#include "Warrior.h"
#include "Characters.h"

Warrior::Warrior(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int regenValue) : Character(name, hp, strength, m_weapon, pos)
{
    this->className = "Warrior";
    this->pain = "I'm basically paid for that.";
    this->death = "That's it, I'm done.";
    this->magicalRes = 15;
    this->physicalRes = 20;
    this->RIP = "    Dead for us. Acting as our tool.    ";
    this->regenValue = regenValue;
    cout << "+-----------------Warrior----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;

}

Warrior::Warrior() : Character::Character()
{
    this->className = "Warrior";
    this->position = { 0, 0 };
    this->name = "warrior00";
    this->hp = 80;
    this->strength = 40;
    this->hpMax = hp;
    this->pain = "I'm basically paid for that.";
    this->death = "That's it, I'm done.";
    this->magicalRes = 15;
    this->physicalRes = 20;
    this->RIP = "    Dead for us. Acting as our tool.    ";
    this->regenValue = 15;
    cout << "+-----------------Warrior----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
}

void Warrior::regenerateHealth()
{
    cout << "|              ------------" << endl;
    cout << "| " << name << " regenerate" << endl;
    cout << "| Regen.   : " << this->getRegenValue() << endl;
    addHealth(regenValue);
    cout << "| New HP   : " << hp << " / " << hpMax << endl;
}

void Warrior::setRegenValue(int value)
{
	regenValue = value;
}

int Warrior::getRegenValue()
{
	return regenValue;
}

void Warrior::displayInfo()
{
    Character::displayInfo();
    cout << "| + Regen. : " << this->getRegenValue() << endl;
    cout << "+----------------------------------------+" << endl;
}
void Warrior::rotativeAttack()
{
    cout << "+----------------------------------------+" << endl;
    cout << "| " << name << " start turning on himself : WOW" << endl;
    cout << "|                -------- " << endl;
    list<Character*> chars = Characters::getInstance()->getList();
    bool hasTouched = false;
    for (list<Character*>::iterator it = chars.begin(); it != chars.end(); ++it)
    {
        if ((*it) != this && attack((*it)) != 0) hasTouched = true;
    }
    if (hasTouched) regenerateHealth();
    cout << "+----------------------------------------+" << endl;
}
