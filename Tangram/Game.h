#pragma once

#include <SDL.h>

class Game {
public: 
	static Game* Instance() {
		if (s_instance == 0) {
			s_instance = new Game();
			return s_instance;
		}
		return s_instance;
	}
	//~Game() {}

	void init() { m_running = true; }
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handle_events();
	void clean();
	bool running() { return m_running; }
	SDL_Renderer* get_renderer() const { return m_renderer; }

private:
	Game(){}
	static Game* s_instance;
	bool m_running;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};
