#include <iostream>
#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        m_keystates = SDL_GetKeyboardState(0);
        if (event.type == SDL_QUIT) {
            Game::Instance()->quit();
           
        }
        if (event.type == SDL_MOUSEBUTTONDOWN) {
                m_mouseButtonPosition->setX(event.button.x);
                m_mouseButtonPosition->setY(event.button.y);
                up = false;
            if (event.button.button == SDL_BUTTON_LEFT) {
                 m_mouseButtonStates[LEFT] = true;
            }

            if (event.button.button == SDL_BUTTON_MIDDLE) {
                m_mouseButtonStates[MIDDLE] = true;
            }

            if (event.button.button == SDL_BUTTON_RIGHT) {
                m_mouseButtonStates[RIGHT] = true;
            }
        }

        if (event.type == SDL_MOUSEBUTTONUP) {
            up = true;
            if (event.button.button == SDL_BUTTON_LEFT) {
                m_mouseButtonStates[LEFT] = false;
            }

            if (event.button.button == SDL_BUTTON_MIDDLE) {
                m_mouseButtonStates[MIDDLE] = false;
            }

            if (event.button.button == SDL_BUTTON_RIGHT) {
                m_mouseButtonStates[RIGHT] = false;
            }
        }

        if (event.type == SDL_MOUSEMOTION) {
            m_mousePosition->setX(event.motion.x);
            m_mousePosition->setY(event.motion.y);
        }
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if (m_keystates != 0) {
        if (m_keystates[key] == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

void InputHandler::clean() {
}
