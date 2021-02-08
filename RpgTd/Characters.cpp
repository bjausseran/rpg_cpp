#include "Characters.h"

Characters* Characters::m_characters = nullptr;

Characters* Characters::getInstance()
{
    if (m_characters == nullptr) {
        m_characters = new Characters();
    }
    return m_characters;
}

Characters::~Characters()
{
    for (list<Character*>::iterator it = players.begin(); it != players.end(); ++it)
    {
        //players.remove(*it);
        delete (*it);
    }
}

list<Character*> Characters::getList()
{
    return players;
}

void Characters::addPlayer(Character *pers)
{
    players.push_back(pers);
}
