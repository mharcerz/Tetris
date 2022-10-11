//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/BlockOnBoard.h"


/*
 * Default position is in the top row at the middle, pattern blocks should be aligned to the middle
 */
//BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block), positionTopLeft({BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, 0}) {}
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block) {

    setHeightWidthTopOfBoolMatrix();
    setPositions(BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2 - 1, - getTopOfBoolMatrix().second - height - 1);
}

sf::Color BlockOnBoard::fieldColor(int x, int y) {
    int block_x = x - getTopLeftCorner().first - 1;
    int block_y = y - getTopLeftCorner().second - 1;

    if (inRange(block_x, block_y) && get(block_x, block_y)) {
        return getColor();
    }
    return sf::Color::Black;
}

void BlockOnBoard::updatePositions() {
    setHeightWidthTopOfBoolMatrix();
    setPositions(getTopLeftCorner().first, getTopLeftCorner().second);
}

bool BlockOnBoard::canIRotate() {

    int dim = MAX_PIECE_WIDTH;

    std::pair<int, int> topLeft;
    topLeft.first = getPositionTopLeft().first - getTopLeftCorner().first - 1;
    topLeft.second = getPositionTopLeft().second - getTopLeftCorner().second - 1;
    std::pair<int, int> downRight;
    downRight.first = getPositionDownRight().first - getTopLeftCorner().first - 1;
    downRight.second = getPositionDownRight().second - getTopLeftCorner().second - 1;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if(topLeft.second == i  && topLeft.first == j)
                if(!isItOnTheBoard(dim - i + getTopLeftCorner().first, j + getTopLeftCorner().second + 1))
                    return false;
            if(downRight.second == i  && downRight.first == j)
                if(!isItOnTheBoard(dim - i + getTopLeftCorner().first, j + getTopLeftCorner().second + 1))
                    return false;
        }
    }
    return true;
}

bool BlockOnBoard::isItOnTheBoard(int x, int y) {

    return x >= 0 && x < BOARD_WIDTH && y >= 0 && y < BOARD_HEIGHT;
}

void BlockOnBoard::setPositions(int x, int y) {
    setTopLeftCorner(x, y);
    setPositionDownRight(x + getTopOfBoolMatrix().first + getWidth(), y + getTopOfBoolMatrix().second + getHeight()); //without -1 because index if about 0 to 3, not 1 to 4
    setPositionTopLeft(x  + getTopOfBoolMatrix().first + 1, y + getTopOfBoolMatrix().second + 1);
}

void BlockOnBoard::setHeightWidthTopOfBoolMatrix() {
    std::pair<int, int> topAndDownY = getTopAndDownY();
    setHeight(topAndDownY);
    std::pair<int, int> leftAndRightX = getLeftAndRightX();
    setWidth(leftAndRightX);
    setTopOfBoolMatrix(leftAndRightX.first, topAndDownY.first);
}

void BlockOnBoard::setTopLeftCorner(int x, int y) {
    topLeftCorner.first = x;
    topLeftCorner.second = y;
}

void BlockOnBoard::setTopOfBoolMatrix(int x, int y) {
    topOfBoolMatrix.first = x;
    topOfBoolMatrix.second = y;
}

void BlockOnBoard::setPositionTopLeft(int x, int y) {
    positionTopLeft.first = x;
    positionTopLeft.second = y;
}

void BlockOnBoard::setPositionDownRight(int x, int y) {
    positionDownRight.first = x;
    positionDownRight.second = y;
}

void BlockOnBoard::setHeight(std::pair<int, int> topAndDownY) {
    height = topAndDownY.second - topAndDownY.first + 1;
}

void BlockOnBoard::setWidth(std::pair<int, int> leftAndRightX) {
    width = leftAndRightX.second - leftAndRightX.first + 1;
}

std::pair<int, int> BlockOnBoard::getTopLeftCorner() {
    return topLeftCorner;
}

std::pair<int, int> BlockOnBoard::getTopOfBoolMatrix() {
    return topOfBoolMatrix;
}

std::pair<int, int> BlockOnBoard::getPositionTopLeft() {
    return positionTopLeft;
}

std::pair<int, int> BlockOnBoard::getPositionDownRight() {
    return positionDownRight;
}

int BlockOnBoard::getHeight() {
    return height;
}

int BlockOnBoard::getWidth() {
    return width;
}