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
#include "SoundManager.h"
#include "InputHandler.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";


void GameOverState::s_none() {

}
void GameOverState::s_gameOverToMain() {
    Game::Instance()->getStateMachine()->dequeState();
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::s_restartPlay() {
    Game::Instance()->getStateMachine()->popState();
    Game::Instance()->getStateMachine()->dequeState();
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
        "restartbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    Object* gameOverText = new MenuButton(new LoaderParams(500, 100, 190, 30, "gameovertext"), s_none);
    Object* button1 = new MenuButton(new LoaderParams(400, 200, 200, 80 , "mainbutton"), s_gameOverToMain);
    Object* button2 = new MenuButton(new LoaderParams(400, 450, 200, 80, "restartbutton"), s_restartPlay);
    
    m_buttons.push_back(gameOverText);
    m_buttons.push_back(button1);
    m_buttons.push_back(button2);

    SoundManager::Instance()->playMusic("2", 0);

    std::cout << "Entering pause state\n" << std::endl;
    return true;
}

bool GameOverState::onExit() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->clean();
    }
    std::vector<Object*>().swap(m_buttons);
    m_buttons.clear();
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        TextureManager::Instance()->clearFromTextureMap("gameovertext");
        TextureManager::Instance()->clearFromTextureMap("mainbutton");
        TextureManager::Instance()->clearFromTextureMap("restartbutton");
    }
    std::cout << "exiting MenuState\n";
	InputHandler::Instance()->reset();
    return true;
}

void GameOverState::update() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->update();
    }
}

void GameOverState::render() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->draw();
    }
}