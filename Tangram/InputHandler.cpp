#include <SDL.h>
#include "InputHandler.h"
#include "Game.h"
#include "Vector2D.h"

InputHandler* InputHandler::s_instance = 0;

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT :
			Game::Instance()->clean();
			break;
		case SDL_MOUSEBUTTONDOWN: 
			on_mouse_button_down(event);
			break;
		case SDL_MOUSEBUTTONUP:
			on_mouse_button_up(event);
			break;
		case  SDL_MOUSEMOTION:
			on_mouse_move(event);
			break;
		default: 
			break;
		}
	}
}

void InputHandler::on_mouse_button_down(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouse_button_states[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouse_button_states[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouse_button_states[RIGHT] = true;
	}
}

void InputHandler::on_mouse_button_up(SDL_Event& event) {
	if (event.button.button == SDL_BUTTON_LEFT) {
		m_mouse_button_states[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE) {
		m_mouse_button_states[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT) {
		m_mouse_button_states[RIGHT] = false;
	}
}

void InputHandler::on_mouse_move(SDL_Event& event) {
	m_mouse_position->set_x(event.motion.x);
	m_mouse_position->set_y(event.motion.y);
}