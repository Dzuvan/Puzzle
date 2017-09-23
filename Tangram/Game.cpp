#include <iostream>
#include "Game.h"
#include "InputHandler.h"

Game* Game::s_instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	flags = 0;
	if (flags) {
		flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_window != 0) {
			std::cout << "Window created\n";
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);

			if (m_renderer != 0) {
				std::cout << "Renderer created\n";
				SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
			}
			else {
				std::cout << "Renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "Window init failed\n";
			return false;
		}
	}
		else {
			std::cout << "SDL init failed\n";
			return false;
		}
		std::cout << "Init success\n";
		m_running = true;
		return true;
	}

void Game::render() {
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Game::update() {

}

void Game::clean() {
	std::cout << "Cleaning game\n";
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::handle_events() {
	InputHandler::Instance()->update();
}

