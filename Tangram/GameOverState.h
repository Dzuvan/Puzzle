#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class GameObject;

class GameOverState {
private:
	static void s_restart_play();
	static const std::string game_over_id;
	std::vector<GameObject*> m_game_objects;
public:
	virtual void update();
	virtual void render();

	virtual bool on_enter();
	virtual bool on_exit();

	virtual	std::string get_state_id() const { return game_over_id; }
};
