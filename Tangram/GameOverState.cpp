#include <iostream>
#include "GameOverState.h"
#include "PlayState.h"
#include "Game.h"

const std::string GameOverState::game_over_id = "GAMEOVER";

bool GameOverState::on_enter() {
	std::cout << "Entering GameOver\n";
	return true;
}

bool GameOverState::on_exit() {
	for (unsigned int i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
	}
	m_game_objects.clear();

	std::cout << "Exiting MenuState\n";
	return true;
}

void GameOverState::update() {
	for (unsigned int i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->update();
	}
	Game::Instance()->get_state_machine()->deque_state();

}

void GameOverState::render() {
	for (unsigned int i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->draw();
	}
}

void GameOverState::s_restart_play() {
	Game::Instance()->get_state_machine()->change_state(new PlayState());
}