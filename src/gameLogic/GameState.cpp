//
// Created by mharc on 01.10.2022.
//

#include "GameState.h"
#include "gameLogic/Factory/ColoredBlockFactory.h"

GameBoard::GameBoard()  {
    for(int i = 0; i < BOARD_WIDTH; i++) {
        for(int j = 0; j < BOARD_HEIGHT; j++) {
            color[i][j] = sf::Color::Black;
        }
    }
}

GameState::GameState() : game_board(),
    current_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())),
    next_block(ColoredBlockFactory::get_colored_block()) {}


sf::Color GameBoard::fieldColor(int x, int y) {
    if(matrix.get(x, y))
        return color[x][y];
    else
        return sf::Color::Black;
}

sf::Color GameState::fieldColor(int x, int y) {
    if(game_board.fieldColor(x, y) != sf::Color::Black)
        return game_board.fieldColor(x, y);
    std::pair <int, int> topAndDownY;
    topAndDownY = current_block.getTopAndDownY();
    int height = topAndDownY.second - topAndDownY.first + 1;
    return current_block.fieldColor(x, y + topAndDownY.first + height);
}

int GameState::update(std::vector<Keys> input, int i) {
    for(auto key: input) {
        if(key == Keys::up || key == Keys::space) {
            current_block.rotate();
        }
    }
    if( i % 10 == 0 ) {
        moveBlockLevelDown();
        return 0;
    } else
        return i;
}

void GameState::moveBlockLevelDown() {

    std::cout << "Y:" << current_block.getPositionY() << std::endl;
    if(current_block.isItOnTheBoard(current_block.getPositionX(), current_block.getPositionY() + 1))
        current_block.setPosition(current_block.getPositionX(), current_block.getPositionY() + 1);
}
