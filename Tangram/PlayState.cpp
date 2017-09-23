#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include <iostream>

const std::string PlayState::play_id = "PLAY";

bool PlayState::on_enter() {
	std::cout << "Entering play state";
	return true;
}

bool PlayState::on_exit() {
	for (unsigned int i = 0; i < m_game_objects.size(); i++) {
		m_game_objects[i]->clean();
	}
	m_game_objects.clear();

	std::cout << "Exiting play state";
	return true;
}

void PlayState::update() {

}

void PlayState::render() {

}