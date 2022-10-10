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
    std::pair<int, int> positionTopLeft;
    std::pair<int, int> positionDownRight;
    int width;
    int height;
    std::pair<int, int> topLeftCorner; // of matrix 4x4 on a boards
    std::pair<int, int> topOfBoolMatrix; //distance of occupied between y value of first colored block and start of matrix<4,4>
public:
    BlockOnBoard(BlockWithColor block);

    void setPositions(int x, int y); //about PositionDownLeft ToDo: about topLeftCorner
    void setPositionTopLeft(int x, int y);
    void setPositionDownRight(int x, int y);
    bool canIRotate();
    void updatePositions();
    std::pair<int, int> getPositionTopLeft();
    std::pair<int, int> getPositionDownRight();
    std::pair<int, int> getTopOfBoolMatrix();
    bool isItOnTheBoard(int x, int y);


    /*
     * returns color of the field for this Block
     * coordinates are in respect to the whole Board
     */
    sf::Color fieldColor(int x, int y);
};

#endif //TETRIS_BLOCKONBOARD_H
