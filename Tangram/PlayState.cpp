#include <iostream>
#include <vector>
#include <string>
#include <SDL.h>
#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "Piece.h"
#include "PauseState.h"
#include "Board.h"
#include "Vec2.h"
#include "Game.h"
#include <random>

const std::string PlayState::s_playID = "PLAY";

bool PlayState::onEnter() {
    std::vector<std::vector<int>> solution_1 = {{300, 500}, {200, 300}, {100, 200}, {500, 500}, {100, 500}, {300, 200}, {200, 100}};
    solutions.push_back(solution_1);
    std::vector<std::vector<int>> solution_2 = {{300, 500}, {200, 300}, {500, 200}, {500, 500}, {100, 500}, {200, 200}, {100, 100}};
    solutions.push_back(solution_2);
    std::vector<std::vector<int>> solution_3 = {{100, 300}, {100, 100}, {100, 500}, {500, 300}, {300, 300}, {300, 500}, {200, 400}};
    solutions.push_back(solution_3);
    std::vector<std::vector<int>> solution_4 = {{100, 200}, {100, 300}, {100, 500}, {500, 300}, {300, 300}, {300, 500}, {200, 400}};
    solutions.push_back(solution_4);
    std::vector<std::vector<int>> solution_5 = {{100, 200}, {100, 300}, {500, 500}, {500, 300}, {300, 300}, {200, 500}, {100, 400}};
    solutions.push_back(solution_5);
    std::vector<std::vector<int>> solution_6 = {{100, 300}, {100, 100}, {500, 500}, {500, 300}, {300, 300}, {200, 500}, {100, 400}};
    solutions.push_back(solution_6);
    std::vector<std::vector<int>> solution_7 = {{400, 200}, {400, 300}, {100, 500}, {300, 300}, {100, 300}, {300, 500}, {200, 400}};
    solutions.push_back(solution_7);
    std::vector<std::vector<int>> solution_8 = {{300, 300}, {200, 100}, {500, 500}, {500, 300}, {100, 300}, {200, 500}, {100, 400}};
    solutions.push_back(solution_8);
    std::vector<std::vector<int>> solution_9 = {{400, 200}, {400, 300}, {500, 500}, {300, 300}, {100, 300}, {200, 500}, {100, 400}};
    solutions.push_back(solution_9);
    std::vector<std::vector<int>> solution_10 = {{300, 300}, {300, 400}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_10);
    std::vector<std::vector<int>> solution_11 = {{300, 500}, {200, 200}, {500, 500}, {500, 300}, {100, 500}, {200, 300}, {100, 100}};
    solutions.push_back(solution_11);
    std::vector<std::vector<int>> solution_12 = {{400, 500}, {200, 200}, {300, 500}, {500, 300}, {100, 500}, {200, 300}, {100, 100}};
    solutions.push_back(solution_12);
    std::vector<std::vector<int>> solution_13 = {{100, 400}, {100, 500}, {100, 200}, {500, 500}, {300, 500}, {300, 200}, {200, 100}};
    solutions.push_back(solution_13);
    std::vector<std::vector<int>> solution_14 = {{300, 300}, {200, 100}, {100, 500}, {500, 300}, {100, 300}, {300, 500}, {200, 400}};
    solutions.push_back(solution_14);
    std::vector<std::vector<int>> solution_15 = {{400, 400}, {400, 500}, {100, 200}, {300, 500}, {100, 500}, {300, 200}, {200, 100}};
    solutions.push_back(solution_15);
    std::vector<std::vector<int>> solution_16 = {{400, 500}, {400, 300}, {100, 200}, {300, 500}, {100, 500}, {300, 200}, {200, 100}};
    solutions.push_back(solution_16);
    std::vector<std::vector<int>> solution_17 = {{400, 500}, {400, 300}, {500, 200}, {300, 500}, {100, 500}, {200, 200}, {100, 100}};
    solutions.push_back(solution_17);
    std::vector<std::vector<int>> solution_18 = {{400, 400}, {400, 500}, {500, 200}, {300, 500}, {100, 500}, {200, 200}, {100, 100}};
    solutions.push_back(solution_18);
    std::vector<std::vector<int>> solution_19 = {{300, 300}, {300, 400}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_19);
    std::vector<std::vector<int>> solution_20 = {{300, 400}, {300, 200}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_20);
    std::vector<std::vector<int>> solution_21 = {{300, 300}, {300, 400}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_21);
    std::vector<std::vector<int>> solution_22 = {{200, 300}, {300, 400}, {400, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_22);
    std::vector<std::vector<int>> solution_23 = {{300, 400}, {300, 200}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_23);
    std::vector<std::vector<int>> solution_24 = {{300, 300}, {300, 400}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_24);
    std::vector<std::vector<int>> solution_25 = {{200, 300}, {300, 400}, {400, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_25);
    std::vector<std::vector<int>> solution_26 = {{300, 400}, {300, 200}, {200, 300}, {500, 300}, {100, 500}, {300, 500}, {100, 100}};
    solutions.push_back(solution_26);
    std::vector<std::vector<int>> solution_27 = {{200, 200}, {400, 500}, {100, 200}, {500, 300}, {100, 500}, {200, 300}, {300, 400}};
    solutions.push_back(solution_27);
    std::vector<std::vector<int>> solution_28 = {{100, 200}, {400, 500}, {300, 200}, {500, 300}, {100, 500}, {200, 300}, {300, 400}};
    solutions.push_back(solution_28);
    std::vector<std::vector<int>> solution_29 = {{400, 300}, {400, 100}, {500, 500}, {300, 300}, {100, 300}, {200, 500}, {100, 400}};
    solutions.push_back(solution_29);
    std::vector<std::vector<int>> solution_30 = {{400, 300}, {400, 100}, {100, 500}, {300, 300}, {100, 300}, {300, 500}, {200, 400}};
    solutions.push_back(solution_30);
    std::vector<std::vector<int>> solution_31 = {{100, 500}, {100, 300}, {100, 200}, {500, 500}, {300, 500}, {300, 200}, {200, 100}};
    solutions.push_back(solution_31);
    std::vector<std::vector<int>> solution_32 = {{300, 400}, {200, 100}, {100, 200}, {500, 300}, {100, 500}, {300, 500}, {200, 200}};
    solutions.push_back(solution_32);

    // Square shape
    int left_x = rand() % (700-500+1) + 500;
    int left_y = rand() % (700-100+1) + 100;
    Vec2 dimension = Vec2(100, 200);
    int right_x = left_x + 100;
    int right_y = left_y;
    Vec2 dimension_2 = Vec2(100, 200);
    SDL_Color color1 = { 255, 0, 0, 0 };
    Piece* piece = new Piece(Vec2(left_x, left_y), Vec2(right_x, right_y), dimension, dimension_2, color1);

    // Underline shape
    int u_left_x= rand() % (700-500+1) + 500;
    int u_left_y = rand() % (700-100+1) + 100;
    Vec2 dimension_u1 = Vec2(100, 100);
    int u_right_x = u_left_x;
    int u_right_y = u_left_y + 100;
    Vec2 dimension_u2 = Vec2(100, 100);
    SDL_Color color2 = { 0, 255, 0, 0 };
    Piece* piece2 = new Piece(Vec2(u_left_x, u_left_y), Vec2(u_right_x, u_right_y), dimension_u1, dimension_u2, color2);

    // IBeam shape
    int i_left_x = rand() % (700 - 500 + 1) + 500;
    int i_left_y = rand() % (700 - 100 + 1) + 100;
    Vec2 dimension_i1 = Vec2(100, 100);
    int i_right_x = i_left_x + 100;
    int i_right_y = i_left_y;
    Vec2 dimension_i2 = Vec2(100, 100);
    SDL_Color color3 = { 0, 0, 255, 0 };
    Piece* piece3 = new Piece(Vec2(i_left_x, i_left_y), Vec2(i_right_x, i_right_y), dimension_i1, dimension_i2, color3);

    // "G" shape
    int g_left_x = rand() % (700 - 500 + 1) + 500;
    int g_left_y = rand() % (700 - 100 + 1) + 100;
    Vec2 dimension_g1 = Vec2(100, 300);
    int g_right_x = g_left_x - 100;
    int g_right_y = g_left_y;
    Vec2 dimension_g2 = Vec2(100, 100);
    SDL_Color color4 = { 100, 0, 255, 0 };
    Piece* piece4 = new Piece(Vec2(g_left_x, g_left_y), Vec2(g_right_x, g_right_y), dimension_g1, dimension_g2, color4);

    //Fat shape
    int f_left_x = rand() % (700 - 500 + 1) + 500;
    int f_left_y = rand() % (700 - 100 + 1) + 100;
    Vec2 dimension_f1 = Vec2( 100, 300);
    int f_right_x = f_left_x + 100;
    int f_right_y = f_left_y + 100;
    Vec2 dimension_f2 = Vec2( 100, 200);
    SDL_Color color5 = { 100, 0, 100, 0 };
    Piece* piece5 = new Piece(Vec2(f_left_x, f_left_y), Vec2(f_right_x, f_right_y), dimension_f1, dimension_f2, color5);

    // L shape
    int l_left_x = rand() % (700 - 500 + 1) + 500;
    int l_left_y = rand() % (700 - 100 + 1) + 100;
    Vec2 dimension_l1 = Vec2(300, 100);
    int l_right_x = l_left_x;
    int l_right_y = l_left_y + 100;
    SDL_Color color6 = { 0, 100, 100, 0 };
    Vec2 dimension_l2 = Vec2(100, 100);
    Piece* piece6 = new Piece(Vec2(l_left_x, l_left_y), Vec2(l_right_x, l_right_y), dimension_l1, dimension_l2, color6);

    // R shape 
    int r_left_x = rand() % (700 - 500 + 1) + 500;
    int r_left_y = rand() % (700 - 100 + 1) + 100;
    Vec2 dimension_r1 = Vec2(300, 100);
    int r_right_x = r_left_x + 200;
    int r_right_y = r_left_y - 100;
    Vec2 dimension_r2 = Vec2(100, 100);
    SDL_Color color7 = { 255, 100, 100, 0 };
    Piece* piece7 = new Piece(Vec2(r_left_x, r_left_y), Vec2(r_right_x, r_right_y), dimension_r1, dimension_r2, color7);

    m_pieces.push_back(piece);
    m_pieces.push_back(piece2);
    m_pieces.push_back(piece3);
    m_pieces.push_back(piece4);
    m_pieces.push_back(piece5);
    m_pieces.push_back(piece6);
    m_pieces.push_back(piece7);

    std::cout << "Entering play state \n" << std::endl;
    return true;
}

bool PlayState::onExit() {
    m_pieces.clear();
    
    std::cout<<"Exiting playState\n"<<std::endl;
    return true;
}

void PlayState::update() {
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for (unsigned int i = 0; i < m_pieces.size(); i++) {
        m_pieces[i]->update();
    }
    Game::Instance()->getStateMachine()->dequeState();
}

void PlayState::render() {
   Board board  = Board(Vec2(100, 100), Vec2(100, 100));
     board.render();
    for (unsigned int i = 0; i < m_pieces.size(); i++) {
        m_pieces[i]->render();
    }
}