#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "InputHandler.h"
#include "Game.h"
#include "Piece.h"
#include "PlayState.h"
#include "MainMenuState.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags){
    if (SDL_Init(SDL_INIT_VIDEO| SDL_INIT_AUDIO | SDL_INIT_TIMER)  == 0) {
        std::cout<<"Subsystem initialization success\n"<<std::endl;
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0) {
            std::cout<<"Window created\n"<<std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                std::cout<<"Renderer created\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            } else {
                std::cout<<"Render initialization failed\n"<<std::endl;
                return false;
            }
        } else {
            std::cout<<"Window initialization failed\n"<<std::endl;
            return false;
        }
    } else {
        std::cout<<"SDL Initialization failed\n"<<std::endl;
        return false;
    }
    std::cout<<"Initialization compstd::vector<std::vector<int>>e\n"<<std::endl;
    
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());

    m_bRunning = true;
    return true;
}

void Game::render() {
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
    SDL_RenderClear(m_pRenderer);    

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
      m_pGameStateMachine->update();
}


void Game::handleEvents() {
    InputHandler::Instance()->update();
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::clean() {
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

void Game::quit() {
    SDL_Quit();
    Game::Instance()->m_bRunning = false;
}