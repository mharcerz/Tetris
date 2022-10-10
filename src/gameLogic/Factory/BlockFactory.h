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
    static std::mt19937 rng;
    static std::uniform_int_distribution<> distr;
    static std::uniform_int_distribution<> dist4;
public:
    static BlockPattern get_random_pattern();
    static int get_number_of_patterns();
};


#endif //TETRIS_BLOCKFACTORY_H
