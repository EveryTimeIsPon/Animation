// AnimatedSprite.h

#ifndef ANIMATIEDSPRITE_H_INCLUDED
#define ANIMATIEDSPRITE_H_INCLUDED

#include "Sprite.h"

struct AnimFrame
{
	float m_duration;
	SDL_Rect m_region;
};

typedef std::vector<AnimFrame> AnimationFrameVector;
typedef std::map<std::string, AnimationFrameVector> AnimationMap;

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(SDL_Texture* texture);

	void Update(float deltatime);

	void AddFrame(const std::string& animationName, const AnimFrame& frame);

	void SetAnimation(const std::string& animationName);

private:
	std::string m_activeAnimationName;
	float m_timer;
	unsigned int m_frame;
	AnimationMap m_animations;
};

#endif // ANIMATEDSPRITE_H_INCLUDED