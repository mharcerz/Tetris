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
    {
        return color[x][y];
    }
    else
        return sf::Color::Black;
}

sf::Color GameState::fieldColor(int x, int y) {
    if(game_board.fieldColor(x, y) != sf::Color::Black)
        return game_board.fieldColor(x, y);
    return current_block.fieldColor(x, y);
}

void GameState::update(std::vector<Keys> input) {
    for(auto key: input) {
        if(key == Keys::up || key == Keys::space) {
            current_block.rotate();
        }
    }
}