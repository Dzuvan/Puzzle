#include <iostream>
#include "Piece.h"
#include "Game.h"
#include "Vec2.h"
#include "InputHandler.h"
#include "Board.h"

void Piece::render() {
    SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), m_color.r, m_color.g, m_color.b, m_color.a);
    SDL_Rect rects[] = {
     m_position.getX(), m_position.getY(), m_dimension.getX(), m_dimension.getY(),
     m_position2.getX(), m_position2.getY(), m_dimension2.getX(), m_dimension2.getY() };

    SDL_RenderFillRects(Game::Instance()->getRenderer(), rects, 2);
    SDL_RenderDrawRects(Game::Instance()->getRenderer(),rects, 2);
}

void Piece::update() {
    if (InputHandler::Instance()->getMouseButtonState(0) &&
        intersects(m_position, m_dimension, *InputHandler::Instance()->getMouseButtonPosition())
        || intersects(m_position2, m_dimension2, *InputHandler::Instance()->getMouseButtonPosition())) {

            offset = (*InputHandler::Instance()->getMouseButtonPosition() - m_position);
            offset2 = (*InputHandler::Instance()->getMouseButtonPosition() - m_position2);

            dragging = true;
    }
    if (InputHandler::Instance()->getBool() && dragging) {
        offset = Vec2(0,0);
        offset2 = Vec2(0,0);
        dragging = false;

        // Snap to grid.
        if (m_position.getX() + m_dimension.getX() > 100 && m_position.getX() + m_dimension.getX() > 100 &&
            m_position.getY() + m_dimension.getY() > 100 && m_position.getY() + m_dimension.getY() < 700 &&
            m_position2.getX()+ m_dimension2.getX() > 100  && m_position2.getX() + m_dimension2.getX() < 700 &&
            m_position2.getY()+ m_dimension2.getY() > 100  && m_position2.getY() + m_dimension2.getY() < 700) {

            m_position.setX((m_position.getX() / 100)*100);
            m_position.setY((m_position.getY() / 100)*100);

            m_position2.setX((m_position2.getX() / 100)*100);
            m_position2.setY((m_position2.getY() / 100)*100);
        }

   }

   if(dragging){
        m_position = *InputHandler::Instance()->getMousePosition() - offset;
        m_position2 = *InputHandler::Instance()->getMousePosition() - offset2;
   }
}

int Piece::getHeight() {
    int height1 = m_position.getY() + m_dimension.getY();
    int height2 = m_position2.getY() + m_dimension2.getY();

    if (height1 > height2)
    return height1;
    else
        return height2;
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

}
