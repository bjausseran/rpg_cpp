#include "Berserk.h"

Berserk::Berserk(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int regenValue) 
    : Warrior(name, hp, strength, m_weapon, pos, regenValue),
        Character(name, hp, strength, m_weapon, pos)
{
    this->className = "Berserk";
    this->pain = "I'm getting stressed out.";
    this->death = "I'm dancing in Valhalla tonight.";
    this->magicalRes = 3;
    this->physicalRes = 9;
    this->RIP = "      To Our Star, our Viqueer.     ";
    cout << "+---------------Berserk-----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;

}

Berserk::Berserk() : Warrior::Warrior()
{
    this->className = "Berserk";
    this->position = { 0, 0 };
    this->name = "berserk00";
    this->hp = 100;
    this->strength = 55;
    this->hpMax = hp;
    this->pain = "I'm getting stressed out.";
    this->death = "I'm dancing in Valhalla tonight.";
    this->magicalRes = 15;
    this->physicalRes = 20;
    this->RIP = "    To Our Star, our Viqueer.    ";
    setRegenValue(15);
    cout << "+---------------Berserk-----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
}

void Berserk::removeHealth(int damage)
{
    if (inBerserk)
    {
        cout << "|              ------------" << endl;
        cout << "| " << (getName() + "      ").substr(0, 9) << ": " << berserkSentence << endl;
        cout << "| " << name << " is not berserk anymore." << endl;
        inBerserk = false;
        cout << "|              ------------" << endl;
    }
    else
    {
        hp = max(0, hp - damage);
        if (hp == 0)
        {
            cout << "| " << (getName() + "      ").substr(0, 9) << ": " << death << endl;
            die();
        }
        else
        {
            if (!hadBerserk && hp < 40) {
                GetInBerserk(true);
            }
            cout << "| New HP   : " << this->hp << " / " << this->hpMax << endl;
            cout << "| " << (getName() + "      ").substr(0, 9) << ": " << pain << endl;
        }
    }
}

void Berserk::addHealth(int potion)
{
    Character::addHealth(potion);
    if (hp == hpMax)
    {
        GetInBerserk(false);
    }
}

void Berserk::GetInBerserk(bool value)
{
    cout << "|              ------------" << endl;
    if (value)
    {
        cout << "| " << name << " is going BERSERK" << endl;
    }
    else
    {
        cout << "| " << name << " is ready to berserk" << endl;
    }
    inBerserk = value;
    hadBerserk = value;
    cout << "|              ------------" << endl;
}
