//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "gameLogic/Block.h"
#include "GameConstants.h"
#include "sfml/UserInput.h"
#include "BoolMatrix.hpp"

enum BlockMovement {move_left, move_right, move_down};// TODO: use?

class GameBoard {
private:
    /*
     * GameBoard consist only of pieces that are already placed
     */
    BoolMatrix <BOARD_WIDTH, BOARD_HEIGHT> matrix;
    sf::Color color[BOARD_WIDTH][BOARD_HEIGHT];

public:
    GameBoard();
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
    void moveBlockLevelDown();
    // TODO: score, speed? (or number of turns), and stuff
public:
    GameState();
    /*
     * use input and move the block every few iterations
     */
    int update(std::vector<Keys> input, int i);

    void processPlayerInput(std::vector<Keys> input);
    /*
     * returns field color based on game_board and current_block
     */
    sf::Color fieldColor(int x, int y);

};


#endif //TETRIS_GAMESTATE_H
