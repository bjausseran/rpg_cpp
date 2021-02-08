#include "GameObject.h"

GameObject::GameObject()
{
	m_characters = Characters::getInstance();
}
GameObject::~GameObject()
{
	delete m_characters;
}