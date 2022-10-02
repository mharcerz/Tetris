//
// Created by mharc on 01.10.2022.
//


#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "SFML/Graphics.hpp"

#include <iostream>

#include "GameConstants.h"
#include "Matrix.h"


// TODO: rethink if the design is fine
class BlockPattern {
private:
    BoolMatrix <MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT> matrix;
public:
    BoolMatrix <MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT> getMatrix();
    BlockPattern(std::vector<std::string> pattern);
    void print_matrix();
};

// TODO: check how to do constructor in prototype design pattern
class BlockWithColor : BlockPattern {
    sf::Color color;
public:
    sf::Color getColor();
    BlockWithColor(BlockPattern pattern, sf::Color color);
};

class BlockOnBoard : BlockWithColor {
    std::pair<int, int> position; // position on the board, top left corner
public:
    BlockOnBoard(BlockWithColor block);

    std::pair<int, int> get_position();
    void rotate();
    /*
     * returns color of the field for this Block
     * coordinates are in respect to the whole Board
     */
    sf::Color fieldColor(int x, int y);
};

#endif //TETRIS_BLOCK_H
