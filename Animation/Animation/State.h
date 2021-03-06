// State.h

#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

class DrawManager;
class InputManager;
class SpriteManager;

struct System
{
	DrawManager* draw_manager;
	InputManager* input_manager;
	SpriteManager* sprite_manager;
};

class State
{
public:
	virtual ~State() {}
	virtual bool Update(float deltatime) = 0;
	virtual void Draw() = 0;
	virtual State* NextState() = 0;
};

#endif // STATE_H_INCLUDED
