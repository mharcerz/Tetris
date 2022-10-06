//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BOOLMATRIX_HPP
#define TETRIS_BOOLMATRIX_HPP

#include <string>
#include <vector>

#include "GameConstants.h"
#include <cassert>


template<int WIDTH, int HEIGHT>
class BoolMatrix {
private:
    bool occupied[WIDTH][HEIGHT];
public:
    BoolMatrix() {
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                occupied[i][j] = false;
            }
        }
    }

    BoolMatrix(std::vector<std::string> pattern) {
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

    bool get(int x, int y) {
        return occupied[x][y];
    }

    bool inRange(int x, int y) {
        return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
    }

    /**
     * rotate clockwise
     */
    void rotate() {
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

    std::pair <int, int> getTopAndDownY()
    {
        int dim = WIDTH;
        std::pair <int, int> topAndDownY;
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
//        for (int i = 0; i < dim; i++) {
//            for (int j = 0; j < dim; j++) {
//                std::cout << occupied[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << "TOP Y: " << getTopY() << std::endl;
//        std::cout << "DOWN Y: " << getDownY() << std::endl;
//
//
//        std::cout << std::endl;
    }

};


#endif //TETRIS_BOOLMATRIX_HPP
