//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_BOOLMATRIX_HPP
#define TETRIS_BOOLMATRIX_HPP

#include <string>
#include <vector>

#include "GameConstants.h"
#include <cassert>


template <int WIDTH, int HEIGHT>
class BoolMatrix {
private:
    bool occupied[WIDTH][HEIGHT];
public:
    BoolMatrix()
    {
        for(int i = 0; i < WIDTH; i++)
        {
            for(int j = 0; j < HEIGHT; j++)
            {
                occupied[i][j] = false;
            }
        }
    }
    BoolMatrix (std::vector <std::string> pattern) {
        // TODO: make it compile time
        assert(pattern.size() == WIDTH);
        for(int i = 0; i < MAX_PIECE_WIDTH; i++)
        {
            assert(pattern[i].size() == HEIGHT);
            for(int j = 0; j < MAX_PIECE_HEIGHT; j++)
            {
                if(pattern[i][j] == '1')
                    occupied[i][j] = true;
                else
                    occupied[i][j] = false;
            }
        }
    }

    bool get(int x, int y)
    {
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

        // TODO: make it prettier
        int cp[4][4];
        for(int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cp[i][j] = occupied[i][j];
            }
        }

        for(int i = 0; i < dim; i++) {
            for(int j = 0; j < dim; j++) {
                occupied[i][j] = cp[j][dim - i - 1];
            }
        }
    }
};




#endif //TETRIS_BOOLMATRIX_HPP
