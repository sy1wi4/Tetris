//
// Created by sylwia on 5/30/21.
//

#include <unistd.h>
#include "Game.h"
#include "GUI.h"


Game::Game() {
    init();
}

void Game::init() {
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
            if (can_rotate()){
                current_piece.rotate();
            }
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
        GameBoard::draw_borders(gui);

        //draw board
        board->draw_stored_pieces(gui);

        // draw next
        draw_next_piece();

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

        if (end_time - start_time > step_time){
            // move down if possible
            if (board->can_move(current_piece, current_x, current_y + 1)){
                current_y += 1;
            }
            else {
                board->place_piece(current_piece, current_x, current_y);
                board->clear_full_lines(gui, current_y);

                if (board->check_game_over()){
                    gui->clear_window();
                    SDL_RenderPresent(gui->getRenderer());
                    sleep(2);
                    quit = true;
                }

                else {
                    current_piece = next_piece;
                    next_piece = pieces->get_random_piece();
                    reset_current_piece_coord();
                }
            }
            start_time = SDL_GetTicks();
        }

        SDL_RenderPresent(gui->getRenderer());
    }

}

void Game::reset_current_piece_coord() {
    // initial position of block
    current_x = cols_number / 2 - block_side / 2;
    current_y = 0;
}

int Game::get_current_x() const {
    return current_x;
}

int Game::get_current_y() const {
    return current_y;
}

bool Game::can_rotate() {
    Piece temp_piece;
    temp_piece = current_piece;
    temp_piece.rotate();

    return board->can_move(temp_piece, current_x, current_y);
}

void Game::draw_next_piece() {
    int start_x = (gui->getWindowWidth() - board_width) / 8;
    int start_y = gui->getWindowHeight() - board_height - square_side;

    SDL_SetRenderDrawColor(gui->getRenderer(), 133, 224, 133, 0xFF);

    for (int i = 0; i < block_side; i++){
        for (int j = 0; j < block_side; j++){

            if (next_piece(i,j)){
                gui->draw_square(start_x + j * square_side,
                                 start_y + i * square_side,
                                 square_side);
            }
        }
    }
}

