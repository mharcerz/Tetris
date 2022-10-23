//
// Created by mharc on 10.10.2022.
//

#ifndef TETRIS_BLOCKPATTERN_H
#define TETRIS_BLOCKPATTERN_H

#include "BoolMatrix.tpp"

class BlockPattern : public BoolMatrix<MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT> {
protected:
public:
    BlockPattern(std::vector<std::string> pattern);
};

#endif //TETRIS_BLOCKPATTERN_H
