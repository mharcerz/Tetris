//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BLOCKFACTORY_H
#define TETRIS_BLOCKFACTORY_H

#include <string>
#include <random>     /* srand, rand */
#include <chrono>

#include "gameLogic/BlockOnBoard.h"

class BlockFactory {
private:
    static std::vector<std::vector<std::string>> available_patterns;

    /*
     * block draw
     */
    static std::mt19937 rng;
    static std::uniform_int_distribution<> distr;
    static std::uniform_int_distribution<> dist4;
    static int get_number_of_patterns();
public:
    /* draw and rotate the pattern */
    static BlockPattern get_random_pattern();

};


#endif //TETRIS_BLOCKFACTORY_H
