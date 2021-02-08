#pragma once
#include "Warrior.h"
class Berserk :
    public virtual Warrior
{
    bool inBerserk = false;
    bool hadBerserk = false;
    string berserkSentence = "Hmm ?";
public :
    Berserk(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos, int regenValue);
    Berserk();


    void removeHealth(int damage) override;
    void addHealth(int potion) override;
    
private:
    void GetInBerserk(bool value);

};

