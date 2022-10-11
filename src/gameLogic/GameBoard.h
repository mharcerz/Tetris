//
// Created by mharc on 09.10.2022.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include "sfml/UserInput.h"
#include "gameLogic/BlockOnBoard.h"
#include "GameConstants.h"
#include "BoolMatrix.tpp"

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
    void putFinishedBlock(BlockOnBoard block, std::pair <int, int> topLeftCorner);
    /*
     * returns the color based on game board
     * Black for empty cells
     */
    sf::Color fieldColor(int x, int y);
};

#endif //TETRIS_GAMEBOARD_H
