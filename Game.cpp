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
    next_piece = pieces->get_random_piece();
    board->print();
    std::cout << "current:" << std::endl << current_piece << std::endl;
    std::cout << "next:" << std::endl << next_piece << std::endl;
    next_piece.draw(gui,10,10);
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
        }

        // draw game

        sleep(1);

    }

}
