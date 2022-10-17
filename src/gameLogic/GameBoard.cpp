//
// Created by mharc on 09.10.2022.
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            color[i][j] = sf::Color::Black;
        }
    }
}

sf::Color GameBoard::fieldColor(int x, int y) {
    if (matrix.get(x, y))
        return color[x][y];
    else
        return sf::Color::Black;
}

bool GameBoard::get(int x, int y) {
    if (y < 0) return false;
    return matrix.get(x, y);
}

void GameBoard::putFinishedBlock(BlockOnBoard block, std::pair<int, int> topLeftCorner) {
    for (int i = topLeftCorner.second; i < topLeftCorner.second + MAX_PIECE_HEIGHT; i++) {
        for (int j = topLeftCorner.first; j < topLeftCorner.first + MAX_PIECE_WIDTH; j++) {
            sf::Color color;
            color = block.fieldColor(j, i);
            if (color != sf::Color::Black) {
                this->color[j][i] = color;
                matrix.setPieceHere(j, i);
            }
        }
    }
}

void GameBoard::update() {

    for (int i = 0; i < BOARD_HEIGHT; i++) {
        // jezeli caly rzad jedynek to zerujemy to i wszystko co na gorze spada o jedno w dół, i jedynki i kolory
        if (isRowFullOfBlock(i)) {
            std::cout << "DUPA" << std::endl;
            //to jest pelny wiersz, wszystko wyzej ma spasc nizej
            matrix.updateRows(i);
            updateColors(i);
            //dodaj do punktacji
        }
    }

}

bool GameBoard::isRowFullOfBlock(int i) {
    for (int j = 0; j < BOARD_WIDTH; j++)
        if (!matrix.get(j, i))
            return false;
    return true;
}

void GameBoard::updateColors(int i) {
    for (i--; i >= 0; i--) {
        sf::Color cp[10];
        for(int j = 0; j < 10; j++) {
            cp[j] = color[j][i];
            color[j][i + 1] = color[j][i];
        }
        for(int j = 0; j < 10; j++) {
            color[j][i] = cp[j];
        }
    }
}