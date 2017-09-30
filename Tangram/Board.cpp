#include <SDL.h>
#include "Board.h"
#include "Vec2.h"
#include "Game.h"

void Board::render(){
   SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 255, 0, 0, 0);
   for ( int x = 0; x < 5; x++) {
       for (int y = 0; y < 5; y++) {
              SDL_Rect rect = {  m_position.getX()+100 * x+1, m_position.getY() + 100*y+1, m_dimension.getX(), m_dimension.getY()};
              SDL_RenderDrawRect(Game::Instance()->getRenderer(),&rect);
       }
   }
}