// GameState.cpp

#include "stdafx.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "SpriteManager.h"
#include "GameState.h"

GameState::GameState(System& system)
{
	m_systems = system;

	m_sprite = m_systems.sprite_manager->CreateAnimatedSprite("../assets/explosion.txt");
	m_sprite->SetAnimation("explosion");
}

GameState::~GameState()
{
	m_systems.sprite_manager->DestroySprite(m_sprite);
	m_sprite = nullptr;
}

bool GameState::Update(float deltatime)
{
	Keyboard* keyboard = m_systems.input_manager->GetKeyboard();
	if (keyboard != nullptr)
	{
		if (keyboard->IsKeyDown(SDLK_ESCAPE))
			return false;
	}

	m_sprite->Update(0.01f);

	return true;
}

void GameState::Draw()
{
	SDL_Rect rect = { 0, 0, 64, 64 };
	m_systems.draw_manager->Draw(m_sprite, &rect);
}

State* GameState::NextState()
{
	return nullptr;
}
