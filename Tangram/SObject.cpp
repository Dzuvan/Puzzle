#include "SObject.h"
#include "TextureManager.h"
#include "Object.h"
#include "Game.h"

SObject::SObject(const LoaderParams *pParams): Object(pParams) {
	m_x = pParams->getX();
	m_y = pParams->getY();

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
        
	m_currentRow = 1;
	m_currentFrame = 1;
}
void SObject::draw()
{   TextureManager::Instance()->drawFrame(m_textureID,(Uint32) m_x,(Uint32) m_y,
            m_width, m_height, m_currentRow, m_currentFrame,
            Game::Instance()->getRenderer());
}

void SObject::update()
{
}

void SObject::clean() {
}