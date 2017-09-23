#pragma once

#include <vector>
#include "GameState.h"

class GameStateMachine {
private:
	std::vector<GameState*> m_game_states;

public:
	void push_state(GameState* state);
	void change_state(GameState* state);
	void pop_state();

	void update();
	void render();

	void deque_state();
};