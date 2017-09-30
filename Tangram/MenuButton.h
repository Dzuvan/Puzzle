#pragma once

#include <string>
#include "SObject.h"
#include "LoaderParams.h"
#include "Vec2.h"

class MenuButton : public SObject {
public:
    MenuButton(const LoaderParams* pParams, void(*callback) ());

    virtual void draw();
    virtual void update();
    virtual void clean();

private:
    enum button_state {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        CLICKED = 2
    };

    void(*m_callback)();
    int m_callbackID;

    bool m_bReleased;

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
    
    int m_numFrames;

    Vec2 m_position;
};
