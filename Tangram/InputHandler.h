#pragma once

#include<SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
private:
	void on_mouse_move(SDL_Event& event);
	void on_mouse_button_down(SDL_Event& event);
	void on_mouse_button_up(SDL_Event& event);
	std::vector<bool> m_mouse_button_states;
	Vector2D* m_mouse_position;
	InputHandler() {
		for (int i = 0; i < 3; i++) {
			m_mouse_button_states.push_back(false);
		}
		m_mouse_position = new Vector2D(0, 0);
	}
	~InputHandler() {}
	static InputHandler* s_instance;

public:
	static InputHandler* Instance()
	{
		if (s_instance == 0) {
			s_instance = new InputHandler();
			return s_instance;
		}
		return s_instance;
	}
	void update();
	void clean();

	void reset() {
		for (int i = 0; i < 3; i++) {
			m_mouse_button_states[i] = false;
		}
	}

	bool get_mouse_button_state(int button_number) {
		return m_mouse_button_states[button_number];
	}
	Vector2D* get_mouse_position() {
		return m_mouse_position;
	}
};