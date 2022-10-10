//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "gameLogic/BlockOnBoard.h"
#include "GameConstants.h"
#include "sfml/UserInput.h"
#include "BoolMatrix.tpp"
#include "GameBoard.h"

class GameState {
private:
    GameBoard game_board;
    BlockOnBoard current_block;
    BlockWithColor next_block;
    void moveBlockLevelDown();
    void moveLeft();
    void moveRight();
    // TODO: score, speed? (or number of turns), and stuff
public:
    GameState();


    /*
     * use input and move the block every few iterations
     */
    int update(std::vector<Keys> input, int i);
    bool canIMove(Keys move);
//    void processPlayerInput(std::vector<Keys> input); ToDo: necessary?
    /*
     * returns field color based on game_board and current_block
     */
    sf::Color fieldColor(int x, int y);

};


#endif //TETRIS_GAMESTATE_H
