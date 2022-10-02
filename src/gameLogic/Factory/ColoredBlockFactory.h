//
// Created by mharc on 01.10.2022.
//
#ifndef TETRIS_COLOREDBLOCKFACTORY_H
#define TETRIS_COLOREDBLOCKFACTORY_H
#include <iostream>
#include <random>     /* srand, rand */
#include <chrono>
#include <string>

#include "gameLogic/Factory/ColorFactory.h"
#include "gameLogic/Block.h"
#include "BlockFactory.h"

class ColoredBlockFactory {
public:
    static BlockWithColor get_colored_block();
};



#endif //TETRIS_COLOREDBLOCKFACTORY_H
