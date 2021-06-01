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
}

void Game::handle_key(SDL_Event e) {

    switch(e.key.keysym.sym){
        case SDLK_LEFT:
            if (board->can_move(current_piece, current_x - 1, current_y)){
                current_x -= 1;
            }
            break;

        case SDLK_RIGHT:
            if (board->can_move(current_piece, current_x + 1, current_y)){
                current_x += 1;
            }
            break;

        case SDLK_DOWN:
            if (board->can_move(current_piece, current_x, current_y + 1)){
                current_y += 1;
            }
            break;

        case SDLK_UP:
            std::cout << "ROTATE" << std::endl;
            break;
    }
}


void Game::start() {
    bool quit = false;

    unsigned int start_time, end_time;
    start_time = SDL_GetTicks();

    while(!quit){
        // clear
        gui->clear_window();

        // draw board borders
        board->draw_borders(gui);

        //draw board
        board->draw_stored_pieces(gui);

        // move
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN){
                handle_key(event);
            }
        }

        // draw moving piece
        current_piece.draw(gui, get_current_x(), get_current_y());

        end_time = SDL_GetTicks();

        if (end_time - start_time > STEP_TIME){
            // move down if possible
            if (board->can_move(current_piece, current_x, current_y + 1)){
                current_y += 1;
            }
            else {
                // TODO: check game over
                board->place_piece(current_piece, current_x, current_y);

                board->clear_full_lines(gui, current_y);

                current_piece = next_piece;
                next_piece = pieces->get_random_piece();
                reset_current_piece_coord();
            }
            start_time = SDL_GetTicks();
        }

        SDL_RenderPresent(gui->getRenderer());
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
