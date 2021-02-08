#include "Shaman.h"

Shaman::Shaman(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int healValue, int regenValue) 
    : Character(name, hp, strength, m_weapon, pos),
        Warrior(name, hp, strength, m_weapon, pos, regenValue),
        Mage(name, hp, strength, m_weapon, pos, healValue),
        Berserk(name, hp, strength, m_weapon, pos, regenValue)
{
    this->className = "Shaman";
    this->magicalRes = 12;
    this->physicalRes = 15;
    this->pain = "I'm feeling the trees inside.";
    this->death = "pretty dead tho";
    this->RIP = "      The dude with no shoes     ";
    cout << "+-----------------Shaman-----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;

}

Shaman::Shaman() :  Mage(), Berserk()
{
    this->className = "Shaman";
    this->position = { 0, 0 };
    this->name = "shaman00";
    this->hp = 75;
    this->strength = 25;
    this->hpMax = hp;
    this->magicalRes = 12;
    this->physicalRes = 15;
    this->pain = "I'm feeling the trees inside.";
    this->death = "pretty dead tho";
    this->RIP = "      The dude with no shoes     ";
    this->healValue = 35;
    cout << "+-----------------Shaman-----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
}

void Shaman::displayInfo()
{
    Character::displayInfo();
    cout << "| + Regen. : " << this->getRegenValue() << endl;
    cout << "| + heal   : " << this->getHealValue() << endl;
    cout << "+----------------------------------------+" << endl;
}

int Shaman::attack(Character* target)
{
    return Berserk::attack(target);
}
