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
    BlockOnBoard next_block;
    int timer = 1;
    bool gameOver;
    void moveBlockLevelDown();
    void moveLeft();
    void moveRight();
    void setGameOver();
    int putFinishedBlock(BlockOnBoard block);
    int putBlock(BlockOnBoard block);
    bool isItCorrect(BlockOnBoard block);
    // TODO: score, speed? (or number of turns), and stuff
public:
    bool getGameOver();
    GameState();


    /*
     * use input and move the block every few iterations
     */
    int update(std::vector<Keys> input);
    bool move(Keys move);
//    void processPlayerInput(std::vector<Keys> input); ToDo: necessary?
    /*
     * returns field color based on game_board and current_block
     */
    sf::Color fieldColor(int x, int y);

};


#endif //TETRIS_GAMESTATE_H
