#pragma once

#include <vector>
#include <string>
#include "GameState.h"

class Object;

class GameOverState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_gameOverID; }
private:
    static void s_gameOverToMain();
    static void s_restartPlay();
    static void s_none();

    static const std::string s_gameOverID;
    std::vector<Object*> m_buttons;
};