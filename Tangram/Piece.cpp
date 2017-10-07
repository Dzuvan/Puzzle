#include <iostream>
#include <SDL_mixer.h>
#include "Piece.h"
#include "Game.h"
#include "Vec2.h"
#include "InputHandler.h"
#include "Board.h"
#include "SoundManager.h"

void Piece::render() {
    SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_Rect rect = { m_position.getX(), m_position.getY(), m_dimension.getX(), m_dimension.getY() };
    SDL_Rect rect2 = { m_position2.getX(), m_position2.getY(), m_dimension2.getX(), m_dimension2.getY() };

    SDL_RenderFillRect(Game::Instance()->getRenderer(), &rect);
    SDL_RenderFillRect(Game::Instance()->getRenderer(), &rect2);
    SDL_RenderDrawRect(Game::Instance()->getRenderer(), &rect2);
    SDL_RenderDrawRect(Game::Instance()->getRenderer(), &rect2);
}

void Piece::update() {
    if (m_selected) {
        if (intersects(m_position, m_dimension, *InputHandler::Instance()->getMouseButtonPosition()) || intersects(m_position2, m_dimension2, *InputHandler::Instance()->getMouseButtonPosition())) {
            if (InputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased) {

                offset = (*InputHandler::Instance()->getMouseButtonPosition() - m_position);
                offset2 = (*InputHandler::Instance()->getMouseButtonPosition() - m_position2);

                dragging = true;
                m_bReleased = false;
            }
        }
    }

        if (!InputHandler::Instance()->getMouseButtonState(LEFT) && dragging) {
            offset = Vec2(0, 0);
            offset2 = Vec2(0, 0);

            dragging = false;
            m_bReleased = true;

            // Snap to grid.
            if (m_position.getX() % 100 != 0 || m_position.getY() % 100 != 0) {
                if (m_position.getX() > 100 && m_position.getX() + m_dimension.getX() > 100 &&
                    m_position.getY() > 100 && m_position.getY() + m_dimension.getY() < 700 &&
                    m_position2.getX() > 100 && m_position2.getX() + m_dimension2.getX() < 700 &&
                    m_position2.getY() > 100 && m_position2.getY() + m_dimension2.getY() < 700) {

                    m_position.setX((m_position.getX() / 100) * 100);
                    m_position.setY((m_position.getY() / 100) * 100);

                    m_position2.setX((m_position2.getX() / 100) * 100);
                    m_position2.setY((m_position2.getY() / 100) * 100);
                    SoundManager::Instance()->playSound("1", 0);
                }
            }
        }

        if (dragging) {

            m_position = *InputHandler::Instance()->getMousePosition() - offset;
            m_position2 = *InputHandler::Instance()->getMousePosition() - offset2;
        }
}

bool Piece::intersects(Vec2 object, Vec2 dimensions, Vec2 mouse) {
    if(mouse.getX() < object.getX() || mouse.getY() < object.getY()) {
        return false;
    }

    if(mouse.getX() > object.getX() + dimensions.getX() || mouse.getY() > object.getY() + dimensions.getY()) {
         return false;
    }
    return true;
}

void Piece::clean() {
    Piece::~Piece();
}

bool Piece::checkWin(std::vector<int> coords) {
    if (m_position.getX() == coords[0] && m_position.getY() == coords[1]) {
        return true;
    }
    return false;
}
