//
// Created by mharc on 10.10.2022.
//

#ifndef TETRIS_BLOCKPATTERN_H
#define TETRIS_BLOCKPATTERN_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include "GameConstants.h"
#include "BoolMatrix.tpp"

// ToDo: rethink if the design is fine
class BlockPattern : public BoolMatrix<4, 4> {
protected:
public:
    BlockPattern(std::vector<std::string> pattern);
};


#endif //TETRIS_BLOCKPATTERN_H
