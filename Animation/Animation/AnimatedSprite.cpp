// AnimatedSprite.cpp

#include "stdafx.h"
#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Texture* texture)
	: Sprite(texture)
{
	m_timer = 0.0f;
	m_frame = 0;
}

void AnimatedSprite::Update(float deltatime)
{
	m_timer += deltatime;

	auto itr = m_animations.find(m_activeAnimationName);
	if (itr != m_animations.end())
	{
		const AnimationFrameVector& vec = itr->second;
		if (m_timer > vec[m_frame].m_duration)
		{
			m_frame++;
			m_frame = m_frame % vec.size();
			m_timer = 0.0f;
		}
		m_region = vec[m_frame].m_region;
	}
}

void AnimatedSprite::AddFrame(const std::string& animationName, const AnimFrame& frame)
{
	auto itr = m_animations.find(animationName);
	if (itr == m_animations.end());
	{
		m_animations.insert(
			std::pair<std::string, AnimationFrameVector>(
			animationName, AnimationFrameVector()
			)
		);
		itr = m_animations.find(animationName);
	}
	itr->second.push_back(frame);
}

void AnimatedSprite::SetAnimation(const std::string& animationName)
{
	m_activeAnimationName = animationName;
	m_frame = 0;

	auto itr = m_animations.find(m_activeAnimationName);
	if (itr != m_animations.end())
	{
		if (itr->second.size() > 0)
			m_region = itr->second[0].m_region;
	}
}