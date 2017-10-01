#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "Game.h"
#include "PauseState.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "InputHandler.h"

const std::string PauseState::s_pauseID = "PAUSE";

bool PauseState::onEnter() {
    if (!TextureManager::Instance()->load("assets/resume.png", "resumebutton",
        Game::Instance()->getRenderer())) {
        return false;
    }
    if (!TextureManager::Instance()->load("assets/main.png", "mainbutton", 
        Game::Instance()->getRenderer())) {
        return false;
    }

    Object* button1 = new MenuButton(new LoaderParams(400, 100, 200, 80, 
            "mainbutton"), s_pauseToMain);
    Object* button2 = new MenuButton(new LoaderParams(400, 300, 200, 80,
            "resumebutton"), s_resumePlay);

    m_buttons.push_back(button1);
    m_buttons.push_back(button2);

    std::cout << "Entering pause state\n" << std::endl;
    return true;
}

bool PauseState::onExit() {
	for (unsigned int i = 0; i < m_buttons.size(); i++) {
		m_buttons[i]->clean();
	}
	m_buttons.clear();
    TextureManager::Instance()->clearFromTextureMap("mainbutton");
    TextureManager::Instance()->clearFromTextureMap("resumebutton");

	// reset the mouse button states to false
	InputHandler::Instance()->reset();

	std::cout << "Exiting pause state\n"<<std::endl;
	return true;
}

void PauseState::s_pauseToMain() {
    std::cout << "Main menu button clicked\n" << std::endl;
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay() {
    std::cout << "Resume button clicked\n" << std::endl;
    Game::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->update();
    }
    Game::Instance()->getStateMachine()->dequeState();
}

void PauseState::render() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->draw();
    }
}