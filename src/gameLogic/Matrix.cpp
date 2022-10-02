//
// Created by mharc on 02.10.2022.
//

#include "Matrix.h"

template <int WIDTH, int HEIGHT>
BoolMatrix<WIDTH, HEIGHT>::BoolMatrix()
{
    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < HEIGHT; j++)
        {
            occupied[i][j] = false;
        }
    }
}

//template <int WIDTH, int HEIGHT>
//bool BoolMatrix<WIDTH, HEIGHT>::get(int x, int y)
//{
//    return occupied[x][y];
//}

template<>
bool BoolMatrix<MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT>::get(int x, int y)
{
    return occupied[x][y];
}

template<>
BoolMatrix<MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT>::BoolMatrix(std::vector <std::string> pattern) {

    for(int i = 0; i < MAX_PIECE_WIDTH; i++)
    {
        for(int j = 0; j < MAX_PIECE_HEIGHT; j++)
        {
            if(pattern[i][j] == '1')
                occupied[i][j] = true;
            else
                occupied[i][j] = false;
        }
    }
}
