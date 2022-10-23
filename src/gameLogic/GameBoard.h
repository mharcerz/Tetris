//
// Created by mharc on 09.10.2022.
//

#ifndef TETRIS_GAMEBOARD_H
#define TETRIS_GAMEBOARD_H

#include <iostream>
#include <cmath>

#include "BlockOnBoard.h"
#include "BoolMatrix.tpp"

class GameBoard {
private:
    /*
     * GameBoard consist only of pieces that are already placed
     */
    int score;
    BoolMatrix <BOARD_WIDTH, BOARD_HEIGHT> matrix;
    sf::Color color[BOARD_WIDTH][BOARD_HEIGHT];
    void clear_rows(int i);
    bool is_row_full_of_blocks(int i);
    void add_to_score(int value);
public:
    GameBoard();
    bool get(int x, int y);
    /*
     * Puts finished Block on the board, removes done lines
     */
    int process_after_move();
    void put_finished_block(BlockOnBoard block, std::pair <int, int> top_left_corner);
    /*
     * returns the color based on game board
     * Black for empty cells
     */
    sf::Color field_color(int x, int y);
    int get_score();
};

#endif //TETRIS_GAMEBOARD_H
