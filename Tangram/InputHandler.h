#pragma once

#include <SDL.h>
#include <vector>
#include "Vec2.h"

enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class InputHandler {
public :
    static InputHandler* Instance() {
        if (s_pInstance == 0) {
            s_pInstance = new InputHandler();
            return s_pInstance;
        }
        return s_pInstance;
    }

    bool getMouseButtonState(int buttonNumber) {
        return m_mouseButtonStates[buttonNumber];
    }

    Vec2* getMousePosition() {
        return m_mousePosition;
    }
    
    Vec2* getMouseButtonPosition() {
        return m_mouseButtonPosition;
    }
   
    bool isKeyDown(SDL_Scancode key);
    
    bool getBool() { return up; }

    void update();
    void clean();
    void reset() {
        for (int i = 0; i < 3; i++) {
            m_mouseButtonStates[i] = false;
        }
    }
private:
    InputHandler() {
        for (int i = 0; i < 3; i++) {
            m_mouseButtonStates.push_back(false);
        }
        m_mousePosition = new Vec2(0, 0);   
        m_mouseButtonPosition = new Vec2(0, 0);
    }
    
    bool up;
    static InputHandler* s_pInstance;
    Vec2* m_mousePosition;
    Vec2* m_mouseButtonPosition;
    const Uint8* m_keystates;
    std::vector<bool> m_mouseButtonStates;
};
