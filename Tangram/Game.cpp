#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "InputHandler.h"
#include "Game.h"
#include "Piece.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "SoundManager.h"
#include "TextureManager.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == 0) {
        std::cout << "Subsystem initialization success\n" << std::endl;
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0) {
            std::cout << "Window created\n" << std::endl;

            SDL_Surface* surface = IMG_Load("assets/tangram.png");
            SDL_SetWindowIcon(m_pWindow, surface);

            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0) {
                std::cout << "Renderer created\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            }
            else {
                std::cout << "Render initialization failed\n" << std::endl;

                return false;
            }
        }
        else {
            std::cout << "Window initialization failed\n" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "SDL Initialization failed\n" << std::endl;
        return false;
    }

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());

    SoundManager::Instance()->load("assets/click-sound.wav", "1", sound_type(1));
    SoundManager::Instance()->load("assets/victory.ogg", "2", sound_type(0));

    std::cout << "Initialization complete" << std::endl;
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
    TTF_Quit();
    SDL_Quit();
}

void Game::quit() {
    SDL_Quit();
    TTF_Quit();
    Game::Instance()->m_bRunning = false;
}
