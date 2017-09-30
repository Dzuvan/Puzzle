#pragma once 

#include "LoaderParams.h"
#include "Vec2.h"
#include "Object.h"
#include <string>

class SObject: public Object {
public:
    SObject(const LoaderParams* pParams);
    
    virtual void draw();
    virtual void update();
    virtual void clean(); 
protected:
    int m_width;
    int m_height;
    
    int m_x;
    int m_y;
    
    int m_currentRow;
    int m_currentFrame;
    
    std::string m_textureID;
};
