#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "PauseState.h"
#include "Board.h"
#include "Vec2.h"

const std::string PlayState::s_playID = "PLAY";

bool PlayState::onEnter() {

    std::cout<<"Entering play state\n"<<std::endl;

    GameObject* object;
    GameObject* object2;
    GameObject* object3;
    GameObject* object4;
    GameObject* object5;
    GameObject* object6;
    GameObject* object7;

    Vec2 position = Vec2(200, 100);
    Vec2 dimension = Vec2(100, 200);
    Vec2 position2 = Vec2(300, 100);
    Vec2 dimension2 = Vec2(100, 200);
    SDL_Color color1 = { 255, 0, 0, 0 };

    object = new GameObject(position, position2, dimension, dimension2, color1);

    Vec2 position21 = Vec2(300, 300);
    Vec2 dimension21 = Vec2(100, 100);
    Vec2 position22 = Vec2(300, 400);
    Vec2 dimension22 = Vec2(100, 100);
    SDL_Color color2 = { 0, 255, 0, 0 };

    object2 = new GameObject(position21, position22, dimension21, dimension22, color2);

    Vec2 position31 = Vec2(400, 400);
    Vec2 dimension31 = Vec2(100, 100);
    Vec2 position32 = Vec2(500, 400);
    Vec2 dimension32 = Vec2(100, 100);
    SDL_Color color3 = { 0, 0, 255, 0 };

     object3 = new GameObject(position31, position32, dimension31, dimension32, color3);

    Vec2 position41 = Vec2(100, 100);
    Vec2 dimension41 = Vec2(100, 300);
    Vec2 position42 = Vec2(0, 100);
    Vec2 dimension42 = Vec2(100, 100);
    SDL_Color color4 = { 100, 0, 255, 0 };

    object4 = new GameObject(position41, position42, dimension41, dimension42, color4);

    Vec2 position51 = Vec2(600, 400);
    Vec2 dimension51 = Vec2(100,300);
    Vec2 position52 = Vec2(700, 500);
    Vec2 dimension52 = Vec2(100, 200);
    SDL_Color color5 = { 100, 0, 100, 0 };

    object5 = new GameObject(position51, position52, dimension51, dimension52, color5);

    Vec2 position61 = Vec2(700, 400);
    Vec2 dimension61 = Vec2(300,100);
    Vec2 position62 = Vec2(700, 500);
    Vec2 dimension62 = Vec2(100, 100);
    SDL_Color color6 = { 0, 100, 100, 0 };

    object6 = new GameObject(position61, position62, dimension61, dimension62, color6);

    Vec2 position71 = Vec2(700, 400);
    Vec2 dimension71 = Vec2(300,100);
    Vec2 position72 = Vec2(900, 300);
    Vec2 dimension72 = Vec2(100,100);
    SDL_Color color7 = { 255, 100, 100, 0 };

    object7 = new GameObject(position71, position72, dimension71, dimension72, color7);

    m_gameObjects.push_back(object);
    m_gameObjects.push_back(object2);
    m_gameObjects.push_back(object3);
    m_gameObjects.push_back(object4);
    m_gameObjects.push_back(object5);
    m_gameObjects.push_back(object6);
    m_gameObjects.push_back(object7);

    return true;
}

bool PlayState::onExit() {
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->clean();
    }
     m_gameObjects.clear();
    
    std::cout<<"Exiting playState\n"<<std::endl;
    return true;
}

void PlayState::update() {
//        if (!lastDragged->getDragged()) {
//        for (auto& Obj : m_gameObjects){
//            if(isOverlapping(lastDragged, Obj)) {
//                lastDragged->setPosition(Vec2(lastDragged->getPosition().getX(), Obj->getPosition().getY()));
//            }
//        }
//    }
//    else {
//        std::vector<GameObject*> Overlaps;
//            for (auto& Obj : m_gameObjects) {
//                if (checkOnTop(Obj)){
//                    Overlaps.push_back(Obj);
//                }
//            }
//            GameObject* lastDragged = findMaxHeight(Overlaps);
//        }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
	Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for (int i = m_gameObjects.size()-1; i >= 0; i--) {
            m_gameObjects[i]->update();
    }
}

void PlayState::render() {
   Board board  = Board(Vec2(100, 100), Vec2(100, 100));
     board.render();
    for (int i = 0; i < m_gameObjects.size(); i++) {
        m_gameObjects[i]->render();
    }
}