//
// Created by sylwia on 5/30/21.
//

#include <unistd.h>
#include "Game.h"
#include "GUI.h"

Game::Game() {
    gui = new GUI();
    board = new GameBoard;
    pieces = new Pieces();

    current_piece = pieces->get_random_piece();
    reset_current_piece_coord();

    next_piece = pieces->get_random_piece();

    board->print();
    std::cout << "current:" << std::endl << current_piece << std::endl;
    std::cout << "next:" << std::endl << next_piece << std::endl;
    std::cout << "current x " << get_current_x() << std::endl;
    std::cout << "current y " << get_current_y() << std::endl;

    current_piece.draw(gui, get_current_x(), get_current_y());
}

void Game::handle_key(SDL_Event e) {

    switch(e.key.keysym.sym){
        case SDLK_LEFT:
            std::cout << "move LEFT" << std::endl;
            if (board->can_move(current_piece, current_x, current_y)){
                std::cout << "OK" << std::endl;
            }
            else{
                std::cout << "NO!" << std::endl << std::endl;

            }
            break;
        case SDLK_RIGHT:
            std::cout << "move RIGHT" << std::endl;
            break;
        case SDLK_DOWN:
            std::cout << "move DOWN" << std::endl;
            break;
        case SDLK_UP:
            std::cout << "ROTATE" << std::endl;
            break;
    }
}


void Game::start() {
    bool quit = false;

    while(!quit){
        // clear
        gui->clear_window();

        // move
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN){
                handle_key(event);
            }
        }

        // draw game

        sleep(1);

    }

}

void Game::reset_current_piece_coord() {
    // initial position of block
    current_x = COLS/2 - BLOCK_SIDE/2;
    current_y = 0;
}

int Game::get_current_x() const {
    return current_x;
}

int Game::get_current_y() const {
    return current_y;
}

const Piece &Game::getCurrentPiece() const {
    return current_piece;
}
