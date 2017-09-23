#include <iostream>
#include <SDL.h>
#include "Game.h"

#define FPS 60
#define DELAY_TIME 1000 / FPS

int main(int argc, char** argv) {
	Uint32 frame_start, frame_time;
	if (Game::Instance()->init("Tangram Puzzle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480, true)) {
		std::cout << "Init success\n";

		while (Game::Instance()->running()) {
			frame_start = SDL_GetTicks();

			Game::Instance()->handle_events();
			Game::Instance()->update();
			Game::Instance()->render();
			
			frame_time = SDL_GetTicks() - frame_start;
			if (frame_time < DELAY_TIME) {
				SDL_Delay((int)(DELAY_TIME - frame_time));
			}
		}
	}
	else {
		std::cout << "Game init failed" << SDL_GetError() << "\n";
		return -1;
	}

	Game::Instance()->clean();
	return 0;
}
