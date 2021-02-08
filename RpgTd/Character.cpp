#include "Character.h" 
#include "Characters.h"  
  	

Character::Character(string name, int hp, int strength, Weapon* m_weapon, vector<int> pos)
{
    this->position = pos;
    this->name = name;
    this->hp = hp;
    this->hpMax = hp;
    this->strength = strength;
    this->m_weapon = m_weapon;
    addWeapon(m_weapon);
    Characters::getInstance()->addPlayer(this);
    cout << "+---------------Character----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
	
}

Character::Character()
{
    this->position = { 0, 0 };
    this->name = "bouffon";
    this->hp = 5;
    this->hpMax = 5;
    this->strength = 5;
    this->m_weapon = new Weapon("Explose", 0, 1);
    addWeapon(m_weapon);
    Characters::getInstance()->addPlayer(this);
    cout << "+---------------Character----------------+" << endl;
    cout << "| " << this->name << " exist " << endl;
    cout << "+----------------------------------------+" << endl;
}

string Character::getClassName()
{
    return className;
}

void Character::setClassName(string className)
{
    this->className = className;
}

Character::~Character()
{
    for (list<Weapon*>::iterator it = weapons.begin(); it != weapons.end(); ++it)
    {
        delete (*it);
    }
    cout << "~ I'm wondering if " << name << " was already dead." << endl;
}


string Character::getName(){return this->name;}

void Character::setName(string name)
{
    this->name = name;
}

void Character::setHealth(int hp){this->hp = hp;}
int Character::getHealth(){return this->hp;}
int Character::getHealthMax() { return this->hpMax; }

void Character::setHealthMax(int hpMax)
{
    this->hpMax = hpMax;
}

void Character::setStrength(int strength){this->hp = strength;}
int Character::getStrength(){return this->strength;}

void Character::setAlive(bool alive)
{
    this->alive = alive;
}

bool Character::getAlive()
{
    return alive;
}

void Character::setPhysicalRes(int res)
{
    this->physicalRes = res;
}

int Character::getPhysicalRes()
{
    return physicalRes;
}

void Character::setMagicalRes(int res)
{
    this->magicalRes = res;
}

int Character::getMagicalRes()
{
    return magicalRes;
}

void Character::move(int x, int y)
{
    cout << "+----------------------------------------+" << endl;
    cout << "| " << this->name << " move " << endl;
    cout << "| from     : (" << this->position[0] << ", " << this->position[1] << ")" << endl;
    position[0] += x;
    position[1] += y;
    cout << "| to       : (" << this->position[0] << ", " << this->position[1] << ")" << endl;
    cout << "+----------------------------------------+" << endl;
}

void Character::setPosition(vector<int> pos)
{
    this->position = pos;
}

vector<int> Character::getPosition()
{
    return this->position;
}

void Character::addHealth(int potion)
{
    hp += potion;
    hp = min(hp, hpMax);
    }

void Character::removeHealth(int damage)
{
    hp = max(0, hp - damage);
    if (hp == 0)
    {
        cout << "| " << (getName() + "      ").substr(0, 9) << ": " << death << endl;
        die();
    }
    else
    {
        cout << "| New HP   : " << this->hp << " / " << this->hpMax << endl;
        cout << "| " << (getName() + "      ").substr(0, 9) << ": " << pain << endl;
    }
}

int Character::attack(Character* target)
{
    if (!target->getAlive() || !alive) return 0;
    int disX = abs(target->getPosition()[0] - position[0]);
    int disY = abs(target->getPosition()[1] - position[1]);
    cout << "| " << name << " attack " << target->name << " with " << m_weapon->getName() << endl;
    cout << "| Range    : " << m_weapon->getRange() << endl;
    cout << "| Distance : " << (disX + disY) << endl;
    if (disX + disY <= m_weapon->getRange())
    {
        cout << "| Phys res : " << target->getPhysicalRes() << endl;
        cout << "| Success  : Damage " << max(this->m_weapon->getDamage() - target->getPhysicalRes(), 0) << endl;
        target->removeHealth(this->m_weapon->getDamage() - target->getPhysicalRes());
        cout << "|                -------- " << endl;
        return this->m_weapon->getDamage() - target->getPhysicalRes();
    }
    else
    {
        cout << "| Fail     : Too far away " << endl;
    }
    cout << "|                -------- " << endl;
    return 0;
}


void Character::die()
{
    alive = false;
    cout << "|                -------- " << endl;
    cout << "|               __________ " << endl;
    cout << "|              /   XXXX   \\ " << endl;
    cout << "|             /    XXXX    \\ " << endl;
    cout << "|            | XXXXXXXXXXXX |" << endl;
    cout << "|            | X" << (this->name + "      ").substr(0,10) << "X |" << endl;
    cout << "|            | XXXXXXXXXXXX |" << endl;
    cout << "|            |     XXXX     |" << endl;
    cout << "|            \\     XXXX     /" << endl;
    cout << "|             \\    XXXX    / " << endl;
    cout << "|              \\   XXXX   / " << endl;
    cout << "|               \\  XXXX  / " << endl;
    cout << "|                \\______/ " << endl;
    cout << "|" << RIP << endl;
}

void Character::displayInfo(){

    cout << "+----------------------------------------+"  << endl;
    cout << "| Name     : " << this->name                        << endl;
    cout << "| Class    : " << this->className << endl;
    cout << "| Position : (" << this->position[0] <<", " << this->position[1] << ")" << endl;
    cout << "| Health   : " << this->hp << " / " << this->hpMax << endl;
    cout << "| Strength : " << this->strength                  << endl;
    cout << "| Phis Res : " << this->physicalRes << endl;
    cout << "| Magic Res: " << this->magicalRes << endl;
    cout << "| Weapon   : " << m_weapon->getName()                 << endl;
    cout << "| Range    : " << m_weapon->getRange() << endl;
    cout << "| Damage   : " << m_weapon->getDamage()            << endl;

}


int Character::addWeapon(string name, int damage, int range)
{
    Weapon* weapon = new Weapon(name, damage, range);
    weapons.push_back(weapon);
    weapon->setId(weapons.size() - 1);
    return weapon->getId();
}
int Character::addWeapon(Weapon* weapon)
{
    weapons.push_back(weapon);
    weapon->setId(weapons.size() - 1);
    return weapon->getId();
}


void Character::removeWeapon(Weapon* weapon)
{
    if (m_weapon == weapon) m_weapon = nullptr;
    weapons.remove(weapon);
    delete(weapon);
}

void Character::removeWeapon(int id)
{
    for (list<Weapon*>::iterator it = weapons.begin(); it != weapons.end(); ++it)
    {
        if ((*it)->getId() == id) {
            if (m_weapon->getId() == id) m_weapon = nullptr;
            weapons.remove((*it));
            delete((*it));
        }
    }
}

void Character::changeWeapon(string name) {
    for (list<Weapon*>::iterator it = weapons.begin(); it != weapons.end(); ++it)
    {
        if ((*it)->getName() == name) {

            cout << "+----------------------------------------+" << endl;
            if (m_weapon != nullptr) cout << "| " << this->name << " change " << this->m_weapon->getName() << " by " << endl;
            else cout << "| " << this->name << " grab " << endl;
            m_weapon = (*it);
            cout << "| ID       : " << m_weapon->getId() << endl;
            cout << "| Name     : " << m_weapon->getName() << endl;
            cout << "| Damage   : " << m_weapon->getDamage() << endl;
            cout << "| Range    : " << m_weapon->getRange() << endl;
            cout << "+----------------------------------------+" << endl;
        }
    }
}
 void Character::changeWeapon(int id) {
     for (list<Weapon*>::iterator it = weapons.begin(); it != weapons.end(); ++it)
     {
         if ((*it)->getId() == id) {

             cout << "+----------------------------------------+" << endl;
             if (m_weapon != nullptr) cout << "| " << this->name << " change " << this->m_weapon->getName() << " by " << endl;
             else cout << "| " << this->name << " grab " << endl;
             m_weapon = (*it);
             cout << "| ID       : " << m_weapon->getId() << endl;
             cout << "| Name     : " << m_weapon->getName() << endl;
             cout << "| Damage   : " << m_weapon->getDamage() << endl;
             cout << "| Range    : " << m_weapon->getRange() << endl;
             cout << "+----------------------------------------+" << endl;
         }
     }
 }




