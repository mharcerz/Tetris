//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "gameLogic/Block.h"
#include "GameConstants.h"
#include "smfl/UserInput.h"

enum BlockMovement {move_left, move_right, move_down};

class GameBoard {
private:
    /*
     * GameBoard consist only of pieces that are already placed
     */
    bool occupied[BOARD_WIDTH][BOARD_HEIGHT];
    sf::Color color[BOARD_WIDTH][BOARD_HEIGHT];

public:
    bool canMove(BlockOnBoard block, BlockMovement move);
    /*
     * Puts finished Block on the board, removes done lines
     */
    void putFinishedBlock();
    /*
     * returns the color based on game board
     * Black for empty cells
     */
    sf::Color fieldColor(int x, int y);
};

class GameState {
private:
    GameBoard game_board;
    BlockOnBoard current_block;
    BlockWithColor next_block;
    // TODO: score, speed? (or number of turns), and stuff
public:
    void processPlayerInput(std::vector<Keys> input);
    /*
     * returns field color based on game_board and current_block
     */
    sf::Color fieldColor(int x, int y);

};


#endif //TETRIS_GAMESTATE_H
