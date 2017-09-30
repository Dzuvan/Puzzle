#pragma once

#include "Vec2.h"

class Board {
public:
    Board(){}
    Board(Vec2 position, Vec2 dimension): m_position(position), m_dimension(dimension) {}
    ~Board() {}
    void render();
    void setPosition( Vec2 position) { m_position = position; }
private:
    Vec2 m_position;
    Vec2 m_dimension;
};