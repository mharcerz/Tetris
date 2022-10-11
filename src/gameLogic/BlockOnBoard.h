//
// Created by mharc on 01.10.2022.
//


#ifndef TETRIS_BLOCKONBOARD_H
#define TETRIS_BLOCKONBOARD_H

#include "SFML/Graphics.hpp"

#include <iostream>

#include "GameConstants.h"
#include "BoolMatrix.tpp"
#include "gameLogic/BlockPattern.h"
#include "gameLogic/BlockWithColor.h"



// TODO: check how to do constructor in prototype design pattern


class BlockOnBoard : public BlockWithColor {
private:
    std::pair<int, int> topLeftCorner; // of matrix 4x4 on a boards
    std::pair<int, int> topOfBoolMatrix; //distance of occupied between y value of first colored block and start of matrix<4,4>
    std::pair<int, int> positionTopLeft;
    std::pair<int, int> positionDownRight;
    int width;
    int height;

public:
    BlockOnBoard(BlockWithColor block);

    /*
     * returns color of the field for this Block
     * coordinates are in respect to the whole Board
     */
    sf::Color fieldColor(int x, int y);

    void updatePositions();
    bool canIRotate();
    bool isItOnTheBoard(int x, int y);

    void setPositions(int x, int y); //about topLeftCorner
    void setHeightWidthTopOfBoolMatrix ();
    void setTopLeftCorner(int x, int y);
    void setTopOfBoolMatrix(int x, int y);
    void setPositionTopLeft(int x, int y);
    void setPositionDownRight(int x, int y);
    void setHeight(std::pair<int, int> topAndDownY);
    void setWidth(std::pair<int, int> leftAndRightX);

    std::pair<int, int> getTopLeftCorner();
    std::pair<int, int> getTopOfBoolMatrix();
    std::pair<int, int> getPositionTopLeft();
    std::pair<int, int> getPositionDownRight();
    int getHeight();
    int getWidth();



};

#endif //TETRIS_BLOCKONBOARD_H
