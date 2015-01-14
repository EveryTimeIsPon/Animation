// StateManager.cpp

#include "stdafx.h"
#include "State.h"
#include "StateManager.h"

StateManager::StateManager()
{
	m_active_state = nullptr;
}

StateManager::~StateManager()
{
	if (m_active_state)
	{
		delete m_active_state;
		m_active_state = nullptr;
	}
}

bool StateManager::Update()
{
	if (!m_active_state)
		return false;
	if (!m_active_state->Update(0.0f))
		SetState(m_active_state->NextState());
	return true;
}

void StateManager::Draw()
{
	if (!m_active_state)
		return;
	m_active_state->Draw();
}

void StateManager::SetState(State* state)
{
	if (m_active_state)
		delete m_active_state;
	m_active_state = state;
}