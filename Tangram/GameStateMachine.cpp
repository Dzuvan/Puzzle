#include "GameStateMachine.h"
#include "InputHandler.h"


void GameStateMachine::push_state(GameState* state) {
	m_game_states.push_back(state);
	m_game_states.back()->on_enter();
}

void GameStateMachine::pop_state() {
	if (!m_game_states.empty()) {
		if (m_game_states.back()->on_exit()) {
			delete m_game_states.back();
			m_game_states.pop_back();
		}
	}
}

void GameStateMachine::change_state(GameState* state) {
	if (!m_game_states.empty()) {
		if (m_game_states.back()->get_state_id() == state->get_state_id()) {
			return;
		}

		if (m_game_states.back()->get_is_valid()) {
			m_game_states.back()->set_is_valid(false);
		}
	}

	m_game_states.push_back(state);
	m_game_states.back()->on_enter();
}

void GameStateMachine::update() {
	if (!m_game_states.empty()) {
		m_game_states.back()->update();
	}
}

void GameStateMachine::render() {
	if (!m_game_states.empty()) {
		m_game_states.back()->render();
	}
}

void GameStateMachine::deque_state() {
	if(!m_game_states.empty()) {
		if (!m_game_states[0]->get_is_valid() && m_game_states[0]->on_exit()) {
			delete m_game_states[0];
			m_game_states.erase(m_game_states.begin());
			InputHandler::Instance()->reset();
		}
	}
}