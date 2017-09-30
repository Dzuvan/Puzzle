#include <iostream>
#include <SDL.h>
#include "Game.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 700;

const int FPS = 30;
const int DELAY_TIME = 1000.0f / FPS;

int main( int argc, char* args[] ) {
    Uint32 frameStart, frameTime;
    std::cout<<"Starting initialization\n"<<std::endl;
    if (Game::Instance()->init("Tangram Puzzle",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT, false)) {
        std::cout<<"Ready to go\n"<<std::endl;
        
        while (Game::Instance()->running()) {
            frameStart = SDL_GetTicks();

            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;

            if (frameTime < DELAY_TIME){
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
    } else {
        std::cout<<"Chuck Testa\n"<<std::endl;
        return -1;
    }
    
    Game::Instance()->clean();
    return 0;
}
