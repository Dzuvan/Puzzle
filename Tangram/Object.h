#pragma once

#include "LoaderParams.h"

class Object {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    Object(const LoaderParams* pParams) {}
    virtual ~Object() {}
};