#pragma once

#include <string>

class GameState {
public: 
    GameState();
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    bool getIsValid() const { return m_isValid; }
    void setIsValid(bool isValid) { m_isValid = isValid; }

    virtual std::string  getStateID() const = 0;
private:
    bool m_isValid;
};