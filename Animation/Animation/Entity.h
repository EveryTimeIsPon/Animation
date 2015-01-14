// Entity.h

#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

class Sprite;

class Entity
{
protected:
	Entity();

public:
	virtual ~Entity();

	virtual void Update(float deltatime) = 0;

	bool HasSprite();
	void SetSprite(Sprite* sprite);
	Sprite* GetSprite();

	float GetX();
	float GetY();
	void SetX(float x);
	void SetY(float y);
	void SetXY(float x, float y);

private:
	Sprite* m_sprite;
	float m_x;
	float m_y;
};

#endif // ENTITY_H_INCLUDED
