#include "AnimatedGraphic.h"
#include "LoaderParams.h"
#include "SObject.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed): SObject(pParams),m_animSpeed(animSpeed) {
}

void AnimatedGraphic::update() {
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::draw() {
    SObject::draw();
}

void AnimatedGraphic::clean() {
    SObject::clean();
}