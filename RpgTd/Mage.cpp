#include "Mage.h"
#include "Characters.h"

Mage::Mage(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int healValue) : Character(name, hp, strength, m_weapon, pos)
{
    this->className = "Mage";
    this->magicalRes = 20;
    this->physicalRes = 3;
    this->pain = "Please, hit the big boi next to me.";
    this->death = "I should've take more potions.";
    this->RIP = " He could heal everyone but not himself...";
    this->healValue = healValue;
    cout << "+------------------Mage------------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
}

Mage::Mage() : Character::Character()
{
    this->className = "Mage";
    this->position = { 0, 0 };
    this->name = "warrior00";
    this->hp = 80;
    this->strength = 40;
    this->hpMax = hp;
    this->magicalRes = 15;
    this->physicalRes = 20;
    this->magicalRes = 20;
    this->physicalRes = 3;
    this->pain = "Please, hit the big boi next to me.";
    this->death = "I should've take more potions.";
    this->RIP = " He could heal everyone but not himself...";
    this->healValue = 40;
}

void Mage::heal(Character* perso)
{
    cout << "+----------------------------------------+" << endl;
    if (perso != this ) cout << "| " << name << " heal " << perso->getName() << endl;
    else cout << "| " << name << " heal himself" << endl;
    cout << "| heal     : " << this->getHealValue() << endl;
    perso->addHealth(healValue);
    cout << "| New HP   : " << perso->getHealth() << " / " << perso->getHealthMax() << endl;
    cout << "+----------------------------------------+" << endl;
}

void Mage::throwFireball(Character* target)
{
    cout << "| " << name << " throw a fireball at " << target->getName() << endl;
    if (target->getAlive())
    {
        cout << "| Magic res: " << target->getMagicalRes() << endl;
        cout << "| Success  : Damage " << max(fireballDamage - target->getMagicalRes(), 0) << endl;
        target->removeHealth(fireballDamage - target->getMagicalRes());
    }
    else
    {
        cout << "| Fail     : The guy is already dead." << endl;
    }
    cout << "+----------------------------------------+" << endl;
}

void Mage::setHealValue(int value)
{
    this->healValue = value;
}

int Mage::getHealValue()
{
    return healValue;
}

void Mage::displayInfo()
{
    Character::displayInfo();
    cout << "| + heal   : " << this->getHealValue() << endl;
    cout << "+----------------------------------------+" << endl;
}
