#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "SObject.h"
#include "LoaderParams.h"

class AnimatedGraphic : public SObject {
public:
    AnimatedGraphic(const LoaderParams* pParams, int anim_speed);

    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    int m_animSpeed;
    int m_numFrames;
};