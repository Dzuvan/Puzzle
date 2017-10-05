#pragma once

#include <vector>
#include <string>
#include "GameState.h"
#include "Piece.h"
#include "Vec2.h"

class PlayState : public GameState {
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID; }

    bool intersects(int, int, int, int, int, int);
private:
    static const std::string s_playID;
 //   std::vector<Piece*> m_pieces;
    std::vector<std::vector<std::vector<int>>> solutions;
};
