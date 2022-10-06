//
// Created by mharc on 01.10.2022.
//


#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "SFML/Graphics.hpp"

#include <iostream>

#include "GameConstants.h"
#include "BoolMatrix.hpp"


// TODO: rethink if the design is fine
class BlockPattern : public BoolMatrix<4, 4> {
protected:
public:
    BoolMatrix <MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT> getMatrix();
    BlockPattern(std::vector<std::string> pattern);
    void print_matrix();
};

// TODO: check how to do constructor in prototype design pattern
class BlockWithColor : public BlockPattern {
    sf::Color color;
public:
    sf::Color getColor();
    BlockWithColor(BlockPattern pattern, sf::Color color);
};

class BlockOnBoard : public BlockWithColor {
    std::pair<int, int> position; // position on the board, top left corner
public:
    BlockOnBoard(BlockWithColor block);

    void setPosition(int x, int y);

    int getPositionX();

    int getPositionY();

    bool isItOnTheBoard(int x, int y);
    /*
     * returns color of the field for this Block
     * coordinates are in respect to the whole Board
     */
    sf::Color fieldColor(int x, int y);
};

#endif //TETRIS_BLOCK_H
