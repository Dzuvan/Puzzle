#include <iostream>
#include <SDL_ttf.h>
#include "GameOverState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "LoaderParams.h"
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
   /* if (!TextureManager::Instance()->load("assets/win-screen.png",
        "gameovertext", Game::Instance()->getRenderer())) {
        return false;
    }*/
    if (!TextureManager::Instance()->load("assets/main.png",
        "mainbutton", Game::Instance()->getRenderer())) {
        return false;
    }
    if (!TextureManager::Instance()->load("assets/restart.png",
        "restartbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    // Object* gameOverText = new MenuButton(new LoaderParams(312, 100, 160, 100 , "gameovertext"), s_none);
    Object* button1 = new MenuButton(new LoaderParams(400, 400, 200, 80 , "mainbutton"), s_gameOverToMain);
    Object* button2 = new MenuButton(new LoaderParams(400, 550, 200, 80, "restartbutton"), s_restartPlay);
    m_buttons.push_back(button1);
    m_buttons.push_back(button2);

    SoundManager::Instance()->playMusic("2", 0);

    std::cout << "Entering pause state\n" << std::endl;
    return true;
}
void GameOverState::drawText(TTF_Font* font, SDL_Color color, char* text, int texW, int texH, int x, int y) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) { 
        std::cout<<"Unable to render text surface! SDL_ttf Error:"<< TTF_GetError()<<std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surface);
    SDL_Rect dstrect = {x, y, texW, texH};
    SDL_RenderCopy(Game::Instance()->getRenderer(), texture, NULL, &dstrect);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_DestroyTexture(texture);
}

bool GameOverState::onExit() {
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->clean();
    }
    std::vector<Object*>().swap(m_buttons);
    m_buttons.clear();
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
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
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("assets/font.ttf", 46);
    drawText(font, { 203, 75, 22, 0 }, "Game Over! You Win!!!!", 700, 100, 200, 200);
    for (unsigned int i = 0; i < m_buttons.size(); i++) {
        m_buttons[i]->draw();
    }
}