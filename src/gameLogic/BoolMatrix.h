//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BOOLMATRIX_H
#define TETRIS_BOOLMATRIX_H

#include <string>
#include <vector>

#include "GameConstants.h"
#include <cassert>

template<int WIDTH, int HEIGHT>
class BoolMatrix {
private:
    bool occupied[WIDTH][HEIGHT];
public:
    BoolMatrix();

    BoolMatrix(std::vector<std::string> pattern);

    bool get(int x, int y);

    bool inRange(int x, int y);

    /**
     * rotate clockwise
     */
    void rotate();

    std::pair<int, int> getTopAndDownY(); //ToDo: make it private

    std::pair <int, int> getLeftAndRightX(); //ToDo: make it private

    std::pair <int, int> getTopLeftCornerOFBlock();

    std::pair <int, int> getDownRightCornerOFBlock();

    void setPieceHere(int x, int y);


};
#include "BoolMatrix.tpp"
#endif //TETRIS_BOOLMATRIX_H
