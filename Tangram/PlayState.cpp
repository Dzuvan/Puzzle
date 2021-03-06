#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <ctime>
#include <algorithm>
#include "PlayState.h"
#include "Game.h"
#include "InputHandler.h"
#include "Piece.h"
#include "PauseState.h"
#include "Board.h"
#include "Vec2.h"
#include "Game.h"
#include "SoundManager.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";

Piece* piece;
Piece* piece2;
Piece* piece3;
Piece* piece4;
Piece* piece5;
Piece* piece6;
Piece* piece7;

bool PlayState::onEnter() {

    // Bez ovoga random uvek bira istu vrednost. 
    srand(time(NULL));
    
    // Sve moguce kombinacije resenja se smestaju u vektor. 
    // Jedno resenje predstavlja vektor od 7 vektora jer se oblici konstruisu na osnovu x i y koordinate prvog dela oblika.
    // Neefikasno ali if it ain't broke don't fix it. 
    std::vector<std::vector<int>> solution_1 = { {300, 400}, {200, 300}, {100, 100}, {500, 300}, {100, 300}, {300, 200}, {200, 100} };
    solutions.push_back(solution_1);
    std::vector<std::vector<int>> solution_2 = { {300, 400}, {200, 300}, {500, 100}, {500, 300}, {100, 300}, {200, 200}, {100, 100} };
    solutions.push_back(solution_2);
    std::vector<std::vector<int>> solution_3 = { {100, 200}, {100, 100}, {100, 400}, {500, 100}, {300, 100}, {300, 500}, {200, 400} };
    solutions.push_back(solution_3);
    std::vector<std::vector<int>> solution_4 = { {100, 100}, {100, 300}, {100, 400}, {500, 100}, {300, 100}, {300, 500}, {200, 400} };
    solutions.push_back(solution_4);
    std::vector<std::vector<int>> solution_5 = { {100, 100}, {100, 300}, {500, 400}, {500, 100}, {300, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_5);
    std::vector<std::vector<int>> solution_6 = { {100, 200}, {100, 100}, {500, 400}, {500, 100}, {300, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_6);
    std::vector<std::vector<int>> solution_7 = { {400, 100}, {400, 300}, {100, 400}, {300, 100}, {100, 100}, {300, 500}, {200, 400} };
    solutions.push_back(solution_7);
    std::vector<std::vector<int>> solution_8 = { {300, 200}, {200, 100}, {500, 400}, {500, 100}, {100, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_8);
    std::vector<std::vector<int>> solution_9 = { {400, 100}, {400, 300}, {500, 400}, {300, 100}, {100, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_9);
    std::vector<std::vector<int>> solution_10 = { {300, 200}, {300, 400}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_10);
    std::vector<std::vector<int>> solution_11 = { {300, 400}, {200, 200}, {500, 400}, {500, 100}, {100, 300}, {200, 300}, {100, 100} };
    solutions.push_back(solution_11);
    std::vector<std::vector<int>> solution_12 = { {400, 400}, {200, 200}, {300, 400}, {500, 100}, {100, 300}, {200, 300}, {100, 100} };
    solutions.push_back(solution_12);
    std::vector<std::vector<int>> solution_13 = { {100, 400}, {100, 300}, {100, 100}, {500, 300}, {300, 300}, {300, 200}, {200, 100} };
    solutions.push_back(solution_13);
    std::vector<std::vector<int>> solution_14 = { {300, 200}, {200, 100}, {100, 400}, {500, 100}, {100, 100}, {300, 500}, {200, 400} };
    solutions.push_back(solution_14);
    std::vector<std::vector<int>> solution_15 = { {400, 300}, {400, 500}, {100, 100}, {300, 300}, {100, 300}, {300, 200}, {200, 100} };
    solutions.push_back(solution_15);
    std::vector<std::vector<int>> solution_16 = { {400, 400}, {400, 300}, {100, 100}, {300, 300}, {100, 300}, {300, 200}, {200, 100} };
    solutions.push_back(solution_16);
    std::vector<std::vector<int>> solution_17 = { {400, 400}, {400, 300}, {500, 100}, {300, 300}, {100, 300}, {200, 200}, {100, 100} };
    solutions.push_back(solution_17);
    std::vector<std::vector<int>> solution_18 = { {400, 300}, {400, 500}, {500, 100}, {300, 300}, {100, 300}, {200, 200}, {100, 100} };
    solutions.push_back(solution_18);
    std::vector<std::vector<int>> solution_19 = { {300, 200}, {300, 400}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_19);
    std::vector<std::vector<int>> solution_20 = { {300, 300}, {300, 200}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_20);
    std::vector<std::vector<int>> solution_21 = { {300, 200}, {300, 400}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_21);
    std::vector<std::vector<int>> solution_22 = { {200, 200}, {300, 400}, {400, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_22);
    std::vector<std::vector<int>> solution_23 = { {300, 300}, {300, 200}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_23);
    std::vector<std::vector<int>> solution_24 = { {300, 200}, {300, 400}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_24);
    std::vector<std::vector<int>> solution_25 = { {200, 200}, {300, 400}, {400, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_25);
    std::vector<std::vector<int>> solution_26 = { {300, 300}, {300, 200}, {200, 200}, {500, 100}, {100, 300}, {300, 500}, {100, 100} };
    solutions.push_back(solution_26);
    std::vector<std::vector<int>> solution_27 = { {200, 100}, {400, 500}, {100, 100}, {500, 100}, {100, 300}, {200, 300}, {300, 400} };
    solutions.push_back(solution_27);
    std::vector<std::vector<int>> solution_28 = { {100, 100}, {400, 500}, {300, 100}, {500, 100}, {100, 300}, {200, 300}, {300, 400} };
    solutions.push_back(solution_28);
    std::vector<std::vector<int>> solution_29 = { {400, 200}, {400, 100}, {500, 400}, {300, 100}, {100, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_29);
    std::vector<std::vector<int>> solution_30 = { {400, 200}, {400, 100}, {100, 400}, {300, 100}, {100, 100}, {300, 500}, {200, 400} };
    solutions.push_back(solution_30);
    std::vector<std::vector<int>> solution_31 = { {100, 400}, {100, 300}, {100, 100}, {500, 300}, {300, 300}, {300, 200}, {200, 100} };
    solutions.push_back(solution_31);
    std::vector<std::vector<int>> solution_32 = { {300, 300}, {200, 100}, {100, 100}, {500, 300}, {100, 300}, {300, 500}, {200, 200} };
    solutions.push_back(solution_32);
    std::vector<std::vector<int>> solution_33 = { {100, 300}, {100, 500}, {500, 100}, {500, 300}, {300, 300}, {200, 200}, {100, 100} };
    solutions.push_back(solution_33);
    std::vector<std::vector<int>> solution_34 = { {100, 400}, {100, 300}, {500, 100}, {500, 300}, {300, 300}, {200, 200}, {100, 100} };
    solutions.push_back(solution_34);
    std::vector<std::vector<int>> solution_35 = { {400, 100}, {200, 100}, {300, 200}, {500, 300}, {100, 100}, {200, 500}, {100, 400} };
    solutions.push_back(solution_35);

    // Oblik kvadrata.
    int left_x = rand() % (750 - 600 + 1) + 600;
    int left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension = Vec2(100, 200);
    int right_x = left_x + 100;
    int right_y = left_y;
    Vec2 dimension_2 = Vec2(100, 200);
    SDL_Color color1 = { 255, 0, 0, 0 };
    piece = new Piece(Vec2(left_x, left_y), Vec2(right_x, right_y), dimension, dimension_2, color1);
    piece->setZ(1);

    // Oblik donje linije(_).
    int u_left_x = rand() % (750 - 600 + 1) + 600;
    int u_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_u1 = Vec2(100, 100);
    int u_right_x = u_left_x + 100;
    int u_right_y = u_left_y;
    Vec2 dimension_u2 = Vec2(100, 100);
    SDL_Color color2 = { 0, 255, 0, 0 };
    piece2 = new Piece(Vec2(u_left_x, u_left_y), Vec2(u_right_x, u_right_y), dimension_u1, dimension_u2, color2);
    piece2->setZ(2);

    // Oblik uspravne linije. 
    int i_left_x = rand() % (750 - 600 + 1) + 600;
    int i_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_i1 = Vec2(100, 100);
    int i_right_x = i_left_x;
    int i_right_y = i_left_y + 100;
    Vec2 dimension_i2 = Vec2(100, 100);
    SDL_Color color3 = { 0, 0, 255, 0 };
    piece3 = new Piece(Vec2(i_left_x, i_left_y), Vec2(i_right_x, i_right_y), dimension_i1, dimension_i2, color3);
    piece3->setZ(3);

    // Oblik obrnutog cirilicnog g slova.
    int g_left_x = rand() % (750 - 600 + 1) + 600;
    int g_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_g1 = Vec2(100, 300);
    int g_right_x = g_left_x - 100;
    int g_right_y = g_left_y;
    Vec2 dimension_g2 = Vec2(100, 100);
    SDL_Color color4 = { 100, 0, 255, 0 };
    piece4 = new Piece(Vec2(g_left_x, g_left_y), Vec2(g_right_x, g_right_y), dimension_g1, dimension_g2, color4);
    piece4->setZ(4);

    //Debeljko od 5 kvadrata.
    int f_left_x = rand() % (750 - 600 + 1) + 600;
    int f_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_f1 = Vec2(100, 300);
    int f_right_x = f_left_x + 100;
    int f_right_y = f_left_y + 100;
    Vec2 dimension_f2 = Vec2(100, 200);
    SDL_Color color5 = { 100, 0, 100, 0 };
    piece5 = new Piece(Vec2(f_left_x, f_left_y), Vec2(f_right_x, f_right_y), dimension_f1, dimension_f2, color5);
    piece5->setZ(5);

    // Oblik oborenog L slova. 
    int l_left_x = rand() % (750 - 600 + 1) + 600;
    int l_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_l1 = Vec2(300, 100);
    int l_right_x = l_left_x + 200;
    int l_right_y = l_left_y - 100;
    SDL_Color color6 = { 0, 100, 100, 0 };
    Vec2 dimension_l2 = Vec2(100, 100);
    piece6 = new Piece(Vec2(l_left_x, l_left_y), Vec2(l_right_x, l_right_y), dimension_l1, dimension_l2, color6);
    piece6->setZ(6);

    // Oblik palog na stomak cirilicnog slova g.
    int r_left_x = rand() % (750 - 600 + 1) + 600;
    int r_left_y = rand() % (500 - 100 + 1) + 100;
    Vec2 dimension_r1 = Vec2(300, 100);
    int r_right_x = r_left_x;
    int r_right_y = r_left_y + 100;
    Vec2 dimension_r2 = Vec2(100, 100);
    SDL_Color color7 = { 255, 100, 100, 0 };
    piece7 = new Piece(Vec2(r_left_x, r_left_y), Vec2(r_right_x, r_right_y), dimension_r1, dimension_r2, color7);
    piece7->setZ(7);

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
    for (unsigned int i = 0; i < m_pieces.size(); i++) {
        m_pieces[i]->clean();
        delete m_pieces[i];
    }
    std::vector<Piece*>().swap(m_pieces);
    InputHandler::Instance()->reset();
    std::cout << "Exiting Play State\n" << std::endl;
    return true;
}

std::vector<int> zs;
std::vector<Piece*> overlaps;

void PlayState::update() {
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R)) {
        for (Piece* p : m_pieces) {
            p->setReset();
        }
    }
    // Biranje dela slagilice koji se pomera.
    // Prvo se pokupe svi delovi ispod kursora.
    // Zatim se proverava koji deo ima najvi�u z vrednost.
    // Poslednje crtani objekat ima najvisu tako da ce se uvek hendlati objekat koji je na vrhu.
    if (InputHandler::Instance()->getMouseButtonState(LEFT)) {
        for(unsigned int i = 0; i < m_pieces.size(); i++) {
            if (intersects(*InputHandler::Instance()->getMouseButtonPosition(),m_pieces[i]->getPosition(), m_pieces[i]->getDimension()) ||
                intersects(*InputHandler::Instance()->getMouseButtonPosition(),m_pieces[i]->getPosition2(), m_pieces[i]->getDimension2())) {

                overlaps.push_back(m_pieces[i]);
                zs.push_back(m_pieces[i]->getZ());
            }
        }
    }

    if (InputHandler::Instance()->getMouseButtonState(LEFT)) {
        for (Piece* o : overlaps) {
            int it = *std::max_element(std::begin(zs), std::end(zs));
            if (o->getZ() == it) {
                o->setSelected(true);
            }
        }
    }
    else {
        for (Piece* o : overlaps) {
                o->setSelected(false);
                overlaps.clear();
                zs.clear();
        }
    }

    for(unsigned int i = 0; i < m_pieces.size(); i++) {
        m_pieces[i]->update();
        // std::cout<<"Piece["<<i<<"]" << "X:" << m_pieces[i]->getPosition().getX() << ", Y:" << m_pieces[i]->getPosition().getY() << std::endl;
        for (std::vector<std::vector<int>> solution : solutions) {
            if (m_pieces[0]->checkWin(solution[0]) &&
                m_pieces[1]->checkWin(solution[1]) &&
                m_pieces[2]->checkWin(solution[2]) &&
                m_pieces[3]->checkWin(solution[3]) &&
                m_pieces[4]->checkWin(solution[4]) &&
                m_pieces[5]->checkWin(solution[5]) &&
                m_pieces[6]->checkWin(solution[6])) {
                Game::Instance()->getStateMachine()->changeState(new GameOverState());
            }
        }
    }
}

void PlayState::render() {
    Board board = Board(Vec2(100, 100), Vec2(100, 100));
    board.render();
    for (unsigned int i = 0; i < m_pieces.size(); i++) {
        m_pieces[i]->render();
    }
    TTF_Init();
    TTF_Font * font = TTF_OpenFont("assets/font.ttf", 46);
    drawText(font, { 255, 255, 0, 0 }, "Tangram Puzzle - the reckonining", 500, 100, 200, 0);
    drawText(font, { 255, 255, 255, 0 }, "Press ESC to pause.", 300, 50, 100, 600);
    drawText(font, { 255, 255, 255, 0 }, "Hold left mouse button to drag a piece.", 500, 50, 100, 650);
}

void PlayState::drawText(TTF_Font* font, SDL_Color color, char* text, int texW, int texH, int x, int y) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (surface == NULL) { 
        std::cout<<"Unable to render text surface! SDL_ttf Error:"<< TTF_GetError()<<std::endl;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surface);
    SDL_Rect dstrect = {x, y, texW, texH};
    SDL_RenderCopy(Game::Instance()->getRenderer(), texture, NULL, &dstrect);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_DestroyTexture(texture);
}

bool PlayState::intersects(Vec2 mouse, Vec2 object, Vec2 dimensions) {
    if(mouse.getX() < object.getX() || mouse.getY() < object.getY()) {
        return false;
    }

    if(mouse.getX() > object.getX() + dimensions.getX() || mouse.getY() > object.getY() + dimensions.getY()) {
         return false;
    }
    return true;
}