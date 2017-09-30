#include <iostream>
#include <SDL.h>
#include "SObject.h"
#include "LoaderParams.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "Game.h"

MenuButton::MenuButton(const LoaderParams* pParams, void(*callback)()): 
            SObject(pParams), m_callback(callback) {
    m_currentFrame = MOUSE_OUT;
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position = Vec2(pParams->getX(), pParams->getY());
	m_currentFrame = 1;
	m_currentRow = 1;
}

void MenuButton::update() {
    Vec2* pMousePos = InputHandler::Instance()->getMousePosition();
	std::cout << "WIDTH: " << m_width << ", HEIGHT: " << m_height << std::endl;
    if (pMousePos->getX() < (m_position.getX() + m_width)
        && pMousePos->getX() > m_position.getX()
        && pMousePos->getY() < (m_position.getY() + m_height)
        && pMousePos->getY() > m_position.getY()) {
        if (InputHandler::Instance()->getMouseButtonState(LEFT) && m_bReleased) {
	std::cout << "X: " << pMousePos->getX() << ", Y: " << pMousePos->getY() << std::endl;
	std::cout << "CLICK" << std::endl;
                m_currentFrame = CLICKED;
                m_callback();
                m_bReleased = false;
        }
        else if (!InputHandler::Instance()->getMouseButtonState(LEFT)) {
				std::cout << "OVER" << std::endl;
                m_bReleased = true;
                m_currentFrame = MOUSE_OVER;
        }
    }
    else {
        m_currentFrame = MOUSE_OUT;
    }
}

void MenuButton::draw() {
    SObject::draw();
}

void MenuButton::clean() {
    SObject::clean();
}