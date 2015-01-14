// GameState.h

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "State.h"

class AnimatedSprite;

class GameState : public State
{
public:
	GameState(System& system);
	~GameState();

	bool Update(float deltatime);
	void Draw();
	State* NextState();

private:
	System m_systems;

	AnimatedSprite* m_sprite;
};

#endif // GAMESTATE_H_INCLUDED
