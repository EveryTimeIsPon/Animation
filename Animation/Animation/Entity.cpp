// Entity.cpp

#include "stdafx.h"
#include "Sprite.h"
#include "Entity.h"

Entity::Entity()
{
	m_sprite = nullptr;
	m_x = 0.0f;
	m_y = 0.0f;
}

Entity::~Entity()
{
}

bool Entity::HasSprite()
{
	return m_sprite != nullptr;
}

void Entity::SetSprite(Sprite* sprite)
{
	m_sprite = sprite;
}

Sprite* Entity::GetSprite()
{
	return m_sprite;
}


float Entity::GetX()
{
	return m_x;
}

float Entity::GetY()
{
	return m_y;
}

void Entity::SetX(float x)
{
	m_x = x;
}

void Entity::SetY(float y)
{
	m_y = y;
}

void Entity::SetXY(float x, float y)
{
	m_x = x;
	m_y = y;
}
