//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/BlockOnBoard.h"


/*
 * Default position is in the top row at the middle, pattern blocks should be aligned to the middle
 */
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block) {

    setHeightWidthTopOfBoolMatrix();
    setTopLeftCorner(BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, -getTopOfBoolMatrix().second - getHeight());
}

BlockOnBoard BlockOnBoard::getRotated() {
    BlockOnBoard result(*this);
    result.rotate();
    return result;
}

BlockOnBoard BlockOnBoard::getMovedDown() {
    BlockOnBoard result(*this);
    result.setTopLeftCorner(result.getTopLeftCorner().first, result.getTopLeftCorner().second + 1);
    return result;
}

BlockOnBoard BlockOnBoard::getMovedRight() {
    BlockOnBoard result(*this);
    result.setTopLeftCorner(result.getTopLeftCorner().first + 1, result.getTopLeftCorner().second);
    return result;
}

BlockOnBoard BlockOnBoard::getMovedLeft() {
    BlockOnBoard result(*this);
    result.setTopLeftCorner(result.getTopLeftCorner().first - 1, result.getTopLeftCorner().second);
    return result;
}
sf::Color BlockOnBoard::fieldColor(int x, int y) {
    int block_x = x - getTopLeftCorner().first;
    int block_y = y - getTopLeftCorner().second;

    if (inRange(block_x, block_y) && get(block_x, block_y)) {
        return getColor();
    }
    return sf::Color::Black;
}

bool BlockOnBoard::isItOnTheBoard(int x, int y) {

    return x >= 0 && x < BOARD_WIDTH && y >= -4 && y < BOARD_HEIGHT;
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

int BlockOnBoard::getHeight() {
    return height;
}

int BlockOnBoard::getWidth() {
    return width;
}