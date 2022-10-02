//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/Block.h"

//BlockMatrix BlockPattern::getMatrix() {
//    return matrix;
//}

BlockPattern::BlockPattern(std::vector<std::string> pattern) : BoolMatrix<4, 4>(pattern) { }

void BlockPattern::print_matrix()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

BlockWithColor::BlockWithColor(BlockPattern pattern, sf::Color color) : BlockPattern(pattern), color(color) {}

sf::Color BlockWithColor::getColor() {
    return color;
}
/*
 * Default position is in the top row at the middle, pattern blocks should be aligned to the middle
 */
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block), position({BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, 0}) {}

sf::Color BlockOnBoard::fieldColor(int x, int y) {
    int block_x = x - position.first;
    int block_y = y - position.second;
    if(inRange(block_x, block_y) && get(block_x, block_y))
    {
        return getColor();
    }
    return sf::Color::Black;
}