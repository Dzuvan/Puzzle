#pragma once

#include <string>
#include <vector>
#include "GameObject.h"
#include "GameState.h"
#include "Object.h"

class MainMenuState: public GameState{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_menuID; }

private:
    static void s_menuToPlay();
    static void s_exitFromMenu();
    
    static const std::string s_menuID;
    std::vector<Object*> m_buttons;
};