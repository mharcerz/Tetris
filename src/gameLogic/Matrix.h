//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H

#include <string>
#include <vector>

#include "GameConstants.h"


template <int WIDTH, int HEIGHT>
class BoolMatrix {
private:
    bool occupied[WIDTH][HEIGHT];
public:
    BoolMatrix();
    BoolMatrix(std::vector<std::string> pattern);
    bool get(int x, int y);


};


#endif //TETRIS_MATRIX_H
