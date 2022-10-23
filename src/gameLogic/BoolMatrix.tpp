//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BOOLMATRIX_TPP
#define TETRIS_BOOLMATRIX_TPP

#include "BoolMatrix.h"

template<int WIDTH, int HEIGHT>
BoolMatrix<WIDTH, HEIGHT>::BoolMatrix() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            occupied[i][j] = false;
        }
    }
}

template<int WIDTH, int HEIGHT>
BoolMatrix<WIDTH, HEIGHT>::BoolMatrix(std::vector<std::string> pattern) {

    for (int i = 0; i < MAX_PIECE_WIDTH; i++) {
        for (int j = 0; j < MAX_PIECE_HEIGHT; j++) {
            if (pattern[i][j] == '1')
                occupied[i][j] = true;
            else
                occupied[i][j] = false;
        }
    }
}

template<int WIDTH, int HEIGHT>
bool BoolMatrix<WIDTH, HEIGHT>::get(int x, int y) {
    return occupied[x][y];
}

template<int WIDTH, int HEIGHT>
bool BoolMatrix<WIDTH, HEIGHT>::in_range(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::rotate() {
    int dim = WIDTH;
    int cp[4][4];
    std::copy(&occupied[0][0], &occupied[0][0] + HEIGHT * WIDTH, &cp[0][0]);

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            occupied[i][j] = cp[j][dim - i - 1];
        }
    }
}

template<int WIDTH, int HEIGHT>
std::pair<int, int> BoolMatrix<WIDTH, HEIGHT>::get_top_and_down_y() {
    int dim = WIDTH;
    std::pair<int, int> top_and_down_y;
    top_and_down_y.first = -1;
    for (int i = 0; i < dim; i++) {
        bool temp = false;
        for (int j = 0; j < dim; j++) {
            if (occupied[j][i] != 0) {
                temp = true;
                break;
            }
        }
        if (top_and_down_y.first == -1 && temp)
            top_and_down_y.first = i; // top of block
        if (temp)
            top_and_down_y.second = i; // down of block
    }
    return top_and_down_y;
}

template<int WIDTH, int HEIGHT>
std::pair<int, int> BoolMatrix<WIDTH, HEIGHT>::get_left_and_right_x() {
    int dim = WIDTH;
    std::pair<int, int> left_and_right_x;
    left_and_right_x.first = -1;
    for (int i = 0; i < dim; i++) {
        bool temp = false;
        for (int j = 0; j < dim; j++) {
            if (occupied[i][j] != 0) {
                temp = true;
                break;
            }
        }
        if (left_and_right_x.first == -1 && temp)
            left_and_right_x.first = i;
        if (temp)
            left_and_right_x.second = i;
    }
    return left_and_right_x;
}

template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::set_piece_here(int x, int y) {
    occupied[x][y] = true;
}

template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::remove_piece_here(int x, int y) {
    occupied[x][y] = false;
}
#endif //TETRIS_BOOLMATRIX_TPP
