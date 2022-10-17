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
    // TODO: make it compile time
    assert(pattern.size() == WIDTH);
    for (int i = 0; i < MAX_PIECE_WIDTH; i++) {
        assert(pattern[i].size() == HEIGHT);
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
bool BoolMatrix<WIDTH, HEIGHT>::inRange(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

/**
 * rotate clockwise
 */
template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::rotate() {
    // TODO: constexpr
    assert(WIDTH == HEIGHT);
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
std::pair<int, int> BoolMatrix<WIDTH, HEIGHT>::getTopAndDownY() {
    int dim = WIDTH;
    std::pair<int, int> topAndDownY;
    topAndDownY.first = -1;
    for (int i = 0; i < dim; i++) {
        bool temp = false;
        for (int j = 0; j < dim; j++) {
            if (occupied[j][i] != 0) {
                temp = true;
                break;
            }
        }
        if (topAndDownY.first == -1 && temp)
            topAndDownY.first = i; // top of block
        if (temp)
            topAndDownY.second = i; // down of block
    }
    return topAndDownY;
}

template<int WIDTH, int HEIGHT>
std::pair<int, int> BoolMatrix<WIDTH, HEIGHT>::getLeftAndRightX() {
    int dim = WIDTH;
    std::pair<int, int> leftAndRightX;
    leftAndRightX.first = -1;
    for (int i = 0; i < dim; i++) {
        bool temp = false;
        for (int j = 0; j < dim; j++) {
            if (occupied[i][j] != 0) {
                temp = true;
                break;
            }
        }
        if (leftAndRightX.first == -1 && temp)
            leftAndRightX.first = i;
        if (temp)
            leftAndRightX.second = i;
    }
    return leftAndRightX;
}

template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::setPieceHere(int x, int y) {
    occupied[x][y] = 1;
}

template<int WIDTH, int HEIGHT>
void BoolMatrix<WIDTH, HEIGHT>::updateRows(int i) {
    for (i--; i >= 0; i--) {
        bool cp[10];
        for(int j = 0; j < 10; j++) {
            cp[j] = occupied[j][i];
            occupied[j][i + 1] = occupied[j][i];
        }
        for(int j = 0; j < 10; j++) {
            occupied[j][i] = cp[j];
        }
    }
}

#endif //TETRIS_BOOLMATRIX_TPP
