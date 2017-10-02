#pragma once

#include <SDL.h>
#include <vector>
#include "Vec2.h"

class Piece{
public:
    Piece():
        m_position(Vec2(0,0)),m_position2(Vec2(0,0)),
        m_dimension(Vec2(0, 0)), m_dimension2(Vec2(0,0)),
        offset(Vec2(0,0)), offset2(Vec2(0,0)),
        dragging(false),
        m_selected(false),
        playing(false)
        {}
    Piece(Vec2 position, Vec2 position2, Vec2 dimension, Vec2 dimension2,SDL_Color color):
        m_position(position), m_position2(position2), m_dimension(dimension), m_dimension2(dimension2), m_color(color) {}
    ~Piece(){
    }

    void render();
    void update();
    void clean();

    int getArea();

    void setOffset(Vec2 off) { offset = off; }
    void setOffset2(Vec2 off2) { offset2 = off2; }

    void setSelected(bool selected) { m_selected = selected;  }
    bool getSelected() { return m_selected;  }

    bool intersects(Vec2, Vec2, Vec2);
    void setPosition(Vec2 position) { m_position = position; }

    Vec2 getPosition() { return m_position; }
    Vec2 getPosition2() { return m_position2; }

    Vec2 getDimension() { return m_dimension; }
    Vec2 getDimension2() { return m_dimension2; }

    bool checkWin(std::vector<int>);

private:
    SDL_Color m_color;

    Vec2 m_position;
    Vec2 m_position2;

    Vec2 m_dimension;
    Vec2 m_dimension2;

    Vec2 offset;
    Vec2 offset2;

    bool dragging;
    bool playing;
    bool m_selected;
};
