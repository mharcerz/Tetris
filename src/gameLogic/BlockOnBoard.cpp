//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/BlockOnBoard.h"


/*
 * Default position is in the top row at the middle, pattern blocks should be aligned to the middle
 */
//BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block), positionTopLeft({BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, 0}) {}
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block) {
    std::pair<int, int> topAndDownY = getTopAndDownY();
    height = topAndDownY.second - topAndDownY.first + 1;
    std::pair<int, int> leftAndRightX = getLeftAndRightX();
    width = leftAndRightX.second - leftAndRightX.first + 1;

    topOfBoolMatrix.first = leftAndRightX.first;
    topOfBoolMatrix.second = topAndDownY.first;
    std::cout << "TopX: " << topOfBoolMatrix.first << std::endl;
    std::cout << "TopY: " << topOfBoolMatrix.second << std::endl;

    // positions on map right down corner of matrix
    setPositions(BOARD_WIDTH / 2 + width / 2 - 1, -1);
//    setPositions(BOARD_WIDTH / 2 - width / 2, -4);
}

std::pair<int, int> BlockOnBoard::getTopOfBoolMatrix() {
    return topOfBoolMatrix;
}

void BlockOnBoard::updatePositions() {

    std::pair<int, int> oldTopLeft = positionTopLeft;
    oldTopLeft.first -= topOfBoolMatrix.first;
    oldTopLeft.second -= topOfBoolMatrix.second;

    std::pair<int, int> topAndDownY = getTopAndDownY();
    height = topAndDownY.second - topAndDownY.first + 1;
    std::pair<int, int> leftAndRightX = getLeftAndRightX();
    width = leftAndRightX.second - leftAndRightX.first + 1;

    topOfBoolMatrix.first = leftAndRightX.first;
    topOfBoolMatrix.second = topAndDownY.first;

    setPositions(oldTopLeft.first + topOfBoolMatrix.first + width - 1, oldTopLeft.second + height - 1 + topOfBoolMatrix.second);

    // for know is alright
}

sf::Color BlockOnBoard::fieldColor(int x, int y) {
    int block_x = x - positionTopLeft.first + topOfBoolMatrix.first;
    int block_y = y - positionTopLeft.second + topOfBoolMatrix.second;

    if (inRange(block_x, block_y) && get(block_x, block_y)) {
        return getColor();
    }
    return sf::Color::Black;
}

void BlockOnBoard::setPositions(int x, int y) {
    std::pair<int, int> topAndDownY = getTopAndDownY();
    std::pair<int, int> leftAndRightX = getLeftAndRightX();

    height = topAndDownY.second - topAndDownY.first + 1;
    width = leftAndRightX.second - leftAndRightX.first + 1;

    setPositionDownRight(x, y);

    setPositionTopLeft(x  - width + 1, y - height + 1);
}

void BlockOnBoard::setPositionTopLeft(int x, int y) {
    positionTopLeft.first = x;
    positionTopLeft.second = y;
}



void BlockOnBoard::setPositionDownRight(int x, int y) {
    positionDownRight.first = x;
    positionDownRight.second = y;
}

std::pair<int, int> BlockOnBoard::getPositionTopLeft() {
    return positionTopLeft;
}

std::pair<int, int> BlockOnBoard::getPositionDownRight() {
    return positionDownRight;
}

bool BlockOnBoard::isItOnTheBoard(int x, int y) {

    return x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT;
}

bool BlockOnBoard::canIRotate() { //it's working :D

    int dim = MAX_PIECE_WIDTH;
    std::pair <int, int> topLeftCorner;
    topLeftCorner.first = positionTopLeft.first - topOfBoolMatrix.first;
    topLeftCorner.second = positionTopLeft.second - topOfBoolMatrix.second;

    std::pair<int, int> topLeft;
    topLeft.first = positionTopLeft.first - topLeftCorner.first;
    topLeft.second = positionTopLeft.second - topLeftCorner.second;
    std::pair<int, int> downRight;
    downRight.first = positionDownRight.first - topLeftCorner.first;
    downRight.second = positionDownRight.second - topLeftCorner.second;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(topLeft.second == i  && topLeft.first == j)
                if(!isItOnTheBoard(dim - i - 1 + topLeftCorner.first, j + topLeftCorner.second))
                    return false;
            if(downRight.second == i  && downRight.first == j)
                if(!isItOnTheBoard(dim - i - 1 + topLeftCorner.first, j + topLeftCorner.second))
                    return false;
        }
    }
    return true;

}