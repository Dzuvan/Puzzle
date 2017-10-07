#pragma once

#include <vector>
#include <string>
#include <SDL_ttf.h>
#include "GameState.h"

class Object;

class GameOverState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_gameOverID; }
    
    void drawText(TTF_Font* font, SDL_Color color, char* text, int texW, int texH, int x, int y);
private:
    static void s_gameOverToMain();
    static void s_restartPlay();
    static void s_none();

    static const std::string s_gameOverID;
    std::vector<Object*> m_buttons;
};