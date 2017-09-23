#pragma once

#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PlayState : public GameState {
private:
	static const std::string play_id;
	std::vector<GameObject*> m_game_objects;
public:
	virtual void update();
	virtual void render();	

	virtual bool on_enter();
	virtual bool on_exit();

	virtual std::string get_state_id() const { return play_id; }
};
