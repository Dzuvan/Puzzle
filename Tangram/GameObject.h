#pragma once

#include "Vec2.h"
#include <SDL.h>

class GameObject {
public:
    GameObject(){}
    GameObject(Vec2 position, Vec2 position2, Vec2 dimension, Vec2 dimension2,SDL_Color color): 
    m_position(position), m_position2(position2), m_dimension(dimension), m_dimension2(dimension2), m_color(color) {}
    ~GameObject(){}
    void render();
    void update();
    void clean();
    int getHeight();
    bool getDragged() { return dragged; }
    void setDragged( bool dr) { dragged = dr; }
    bool intersects(Vec2, Vec2, Vec2);
    Vec2 setPosition(Vec2 position) { m_position = position; }
    Vec2 getPosition() { return m_position; }

private:
    SDL_Color m_color;
    Vec2 m_position;
    Vec2 m_position2;
    Vec2 m_dimension;
    Vec2 m_dimension2;
    Vec2 offset;    
    Vec2 offset2;
    bool dragging;
    bool dragged;
    bool m_onTop;
};
