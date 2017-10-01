#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "Game.h"
#include "MenuButton.h"

const std::string MainMenuState::s_menuID = "MENU";

bool MainMenuState::onEnter() {
    if (!TextureManager::Instance()->load("assets/button.png", "playbutton",
            Game::Instance()->getRenderer())) {
        return false;
    }
    if (!TextureManager::Instance()->load("assets/exit.png", "exitbutton",
            Game::Instance()->getRenderer())) {
        return false;
    }

    Object* button1 = new MenuButton(new LoaderParams(300, 200, 400, 100,
            "playbutton"), s_menuToPlay);
    Object* button2 = new MenuButton(new LoaderParams(300, 400, 400, 100,
            "exitbutton"),s_exitFromMenu);

    m_buttons.push_back(button1);
    m_buttons.push_back(button2);

    std::cout << "Entering menu state" << std::endl;
    return true;
}

bool MainMenuState::onExit() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->clean();
    }
    m_buttons.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");

    std::cout << "Exiting menu state\n"<<std::endl;
    return true;
}

void MainMenuState::update() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->update();
    }
    Game::Instance()->getStateMachine()->dequeState();
}

void MainMenuState::render() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->draw();
    }
}

void MainMenuState::s_menuToPlay() {
    std::cout << "Play button clicked\n"<<std::endl;
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() {
    std::cout << "Exit button clicked\n" << std::endl;
    Game::Instance()->quit();
}
