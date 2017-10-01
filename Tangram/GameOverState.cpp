#include <iostream>
#include <vector>
#include <string>
#include "GameOverState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "AnimatedGraphic.h"
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain() {
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter() {
    if (!TextureManager::Instance()->load("assets/gameover.png",
        "gameovertext", Game::Instance()->getRenderer())) {
        return false;
    }
    if (!TextureManager::Instance()->load("assets/main.png",
        "mainbutton", Game::Instance()->getRenderer())) {
        return false;
    }
    if (!TextureManager::Instance()->load("assets/restart.png",
        "restart", Game::Instance()->getRenderer())) {
        return false;
    }

    Object* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);
    Object* button1 = new MenuButton(new LoaderParams(400, 200, 200, 80, "mainbutton"), s_gameOverToMain);
    Object* button2 = new MenuButton(new LoaderParams(400, 300, 200, 80, "restartbutton"), s_restartPlay);
    
    m_buttons.push_back(gameOverText);
    m_buttons.push_back(button1);
    m_buttons.push_back(button2);

    std::cout << "Entering pause state\n" << std::endl;
    return true;
}

bool GameOverState::onExit() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->clean();
    }
    m_buttons.clear();

    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        TextureManager::Instance()->clearFromTextureMap("gameovertext");
        TextureManager::Instance()->clearFromTextureMap("mainbutton");
        TextureManager::Instance()->clearFromTextureMap("restartbutton");
    }

    std::cout << "exiting MenuState\n";
    return true;
}

void GameOverState::update() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->update();
    }
    Game::Instance()->getStateMachine()->dequeState();
}

void GameOverState::render() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->draw();
    }
}