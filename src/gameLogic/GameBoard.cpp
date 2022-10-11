//
// Created by mharc on 09.10.2022.
//

#include "GameBoard.h"

GameBoard::GameBoard()  {
    for(int i = 0; i < BOARD_WIDTH; i++) {
        for(int j = 0; j < BOARD_HEIGHT; j++) {
            color[i][j] = sf::Color::Black;
        }
    }
}

sf::Color GameBoard::fieldColor(int x, int y) {
    if(matrix.get(x, y))
        return color[x][y];
    else
        return sf::Color::Black;
}

void GameBoard::putFinishedBlock(BlockOnBoard block, std::pair <int, int> topLeftCorner) {

    for(int i = topLeftCorner.second; i < topLeftCorner.second + MAX_PIECE_HEIGHT; i++) {
        for(int j = topLeftCorner.first; j < topLeftCorner.first + MAX_PIECE_WIDTH; j++) {
            sf::Color color;
            color = block.fieldColor(j, i);
            if(color != sf::Color::Black) {
                this->color[j][i] = color;
                matrix.setPieceHere(j, i);
            }
        }
    }
}