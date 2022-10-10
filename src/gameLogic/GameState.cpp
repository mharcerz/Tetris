//
// Created by mharc on 01.10.2022.
//

#include "GameState.h"
#include "gameLogic/Factory/ColoredBlockFactory.h"



GameState::GameState() : game_board(),
    current_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())),
    next_block(ColoredBlockFactory::get_colored_block()) {}




//sf::Color GameState::fieldColor(int x, int y) {
//    if(game_board.fieldColor(x, y) != sf::Color::Black)
//        return game_board.fieldColor(x, y);
//    std::pair <int, int> topAndDownY;
//    topAndDownY = current_block.getTopAndDownY();
//    int height = topAndDownY.second - topAndDownY.first + 1;
//    return current_block.fieldColor(x, y + topAndDownY.first + height);
//}

sf::Color GameState::fieldColor(int x, int y) {
    if(game_board.fieldColor(x, y) != sf::Color::Black)
    {
        return game_board.fieldColor(x, y);
    }
    return current_block.fieldColor(x, y);



}
int GameState::update(std::vector<Keys> input, int i) {
    for(auto key: input) {
        if(key == Keys::up || key == Keys::space) {
            if(current_block.canIRotate())
            {
                current_block.rotate();
                current_block.updatePositions();
            }
        }  else if(key == Keys::left) {
            moveLeft();
        }  else if(key == Keys::right) {
            moveRight();
        } else if(key == Keys::down) {
            moveBlockLevelDown();
            i = 1;
        }
    }
    if(current_block.getPositionDownLeft().second == BOARD_HEIGHT - 1)
    {
        std::pair <int, int> topLeftCorner;
        topLeftCorner.first = current_block.getPositionTopLeft().first - current_block.getTopOfBoolMatrix().first;
        topLeftCorner.second = current_block.getPositionTopLeft().second - current_block.getTopOfBoolMatrix().second;
        game_board.putFinishedBlock(current_block, topLeftCorner);
        current_block = next_block;
        next_block = (ColoredBlockFactory::get_colored_block());
    }

    if( i % 10 == 0 ) {
        moveBlockLevelDown();
        return 0;
    } else
        return i;


}

//void GameState::moveBlockLevelDown() {
//    std::cout << "TopY: " <<  current_block.getPositonTopLeftY() << std::endl;
//    if(current_block.isItOnTheBoard(current_block.getPositionTopLeftX(), current_block.getPositonTopLeftY() + 1))
//        current_block.setPositionTopLeft(current_block.getPositionTopLeftX(), current_block.getPositonTopLeftY() + 1);
//}
bool GameState::canIMoveLevelDown() {
    //hard
}
void GameState::moveBlockLevelDown() {
//    std::cout << "DownY: " <<  current_block.getPositionDownLeft().second << std::endl;
    if(current_block.isItOnTheBoard(current_block.getPositionTopLeft().first, current_block.getPositionDownLeft().second + 1))
        current_block.setPositions(current_block.getPositionTopLeft().first, current_block.getPositionDownLeft().second + 1);
}


void GameState::moveRight() {
    std::cout << "TOP RIGHT: " << current_block.getPositionDownRight().first + 1 << std::endl;
    if(current_block.isItOnTheBoard(current_block.getPositionDownRight().first + 1, current_block.getPositionDownRight().second))
        current_block.setPositions(current_block.getPositionDownLeft().first + 1, current_block.getPositionDownLeft().second);
}

void GameState::moveLeft() {
//    std::cout << "TOP RIGHT: " << current_block.getPositionTopRight().first + 1 << std::endl;
    if(current_block.isItOnTheBoard(current_block.getPositionDownLeft().first - 1, current_block.getPositionDownLeft().second))
        current_block.setPositions(current_block.getPositionDownLeft().first - 1, current_block.getPositionDownLeft().second);
}
