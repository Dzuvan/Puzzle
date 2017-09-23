#pragma once

#include <string>
#include <vector>

class GameState {
private:
	bool m_is_valid;
public:
	GameState();
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool on_enter() = 0;
	virtual bool on_exit() = 0;

	virtual std::string get_state_id() const = 0;

	bool get_is_valid() { return m_is_valid; }
	void set_is_valid(bool is_valid) { m_is_valid = is_valid; }
};
