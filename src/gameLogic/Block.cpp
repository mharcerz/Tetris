//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/Block.h"

//BlockMatrix BlockPattern::getMatrix() {
//    return matrix;
//}

BlockPattern::BlockPattern(std::vector<std::string> pattern) : matrix(pattern){ }

void BlockPattern::print_matrix()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

BlockWithColor::BlockWithColor(BlockPattern pattern, sf::Color color) : BlockPattern(pattern), color(color) {}

/*
 * Default position is in the top row at the middle, pattern blocks should be aligned to the middle
 */
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block), position({BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, 0}) {}