//
// Created by mharc on 10.10.2022.
//

#ifndef TETRIS_BLOCKWITHCOLOR_H
#define TETRIS_BLOCKWITHCOLOR_H

#include "SFML/Graphics.hpp"

#include <iostream>

#include "GameConstants.h"
#include "BoolMatrix.tpp"
#include "gameLogic/BlockPattern.h"

class BlockWithColor : public BlockPattern {
    sf::Color color;
public:
    sf::Color getColor();
    BlockWithColor(BlockPattern pattern, sf::Color color);
};


#endif //TETRIS_BLOCKWITHCOLOR_H
