//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BOOLMATRIX_H
#define TETRIS_BOOLMATRIX_H

#include <string>
#include <vector>

#include "GameConstants.h"

template<int WIDTH, int HEIGHT>
class BoolMatrix {
private:
    bool occupied[WIDTH][HEIGHT];
public:
    BoolMatrix();
    explicit BoolMatrix(std::vector<std::string> pattern);
    bool get(int x, int y);
    bool in_range(int x, int y);
    void rotate();
    std::pair<int, int> get_top_and_down_y();
    std::pair <int, int> get_left_and_right_x();
    void set_piece_here(int x, int y);
    void remove_piece_here(int x, int y);
};
#include "BoolMatrix.tpp"

#endif //TETRIS_BOOLMATRIX_H
