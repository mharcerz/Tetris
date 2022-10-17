//
// Created by mharc on 01.10.2022.
//

#include "GameState.h"
#include "gameLogic/Factory/ColoredBlockFactory.h"

GameState::GameState() : game_board(),
                         current_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())),
                         next_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())) {
    timer = 1;
    gameOver = false;
}

sf::Color GameState::fieldColor(int x, int y) {
    if (game_board.fieldColor(x, y) != sf::Color::Black) {
        return game_board.fieldColor(x, y);
    }
    return current_block.fieldColor(x, y);
}

int GameState::update(std::vector<Keys> input) {
    for (auto key: input) {
        if (key == Keys::up || key == Keys::space)
            move(Keys::rotate);
        else if (key == Keys::left)
            move(Keys::left);
        else if (key == Keys::right)
            move(Keys::right);
        else if (key == Keys::down) {
            move(Keys::down);
            timer = 1;
        }
    }
    game_board.update();
    if (timer % 10 == 0) {
        move(Keys::down);
        timer = 1;
    } else
        timer++;

}

bool GameState::move(Keys move) {
    switch (move) {
        case left: {
            BlockOnBoard movedLeft(current_block.getMovedLeft());
            if (isItCorrect(movedLeft)) {
                current_block = movedLeft;
            }
            break;
        }
        case right: {
            BlockOnBoard movedRight(current_block.getMovedRight());
            if (isItCorrect(movedRight)) {
                current_block = movedRight;
            }
            break;
        }
        case down: {
            BlockOnBoard movedDown(current_block.getMovedDown());
            if (isItCorrect(movedDown)) {
                current_block = movedDown;
                std::cout << "X: " << current_block.getTopLeftCorner().first << std::endl;
                std::cout << "Y: " << current_block.getTopLeftCorner().second << std::endl;
            } else putFinishedBlock(movedDown);
            break;
        }
        case rotate: {
            BlockOnBoard rotated(current_block.getRotated());
            if (isItCorrect(rotated)) {
                current_block = rotated;
            }
            break;
        }
        default:
            break;

    }
}

bool GameState::isItCorrect(BlockOnBoard block) {
    for (int i = 0; i < MAX_PIECE_HEIGHT; i++) {
        for (int j = 0; j < MAX_PIECE_WIDTH; j++) {

            if ((game_board.get(block.getTopLeftCorner().first + j, block.getTopLeftCorner().second + i) &&
                 block.get(j, i)) ||
                (block.get(j, i) && !block.isItOnTheBoard(block.getTopLeftCorner().first + j,
                                                          block.getTopLeftCorner().second + i)))
                return false;
        }
    }
    return true;
}

int GameState::putFinishedBlock(BlockOnBoard block) {
    for (int i = 0; i < MAX_PIECE_HEIGHT; i++) {
        for (int j = 0; j < MAX_PIECE_WIDTH; j++) {
            if ((!block.isItOnTheBoard(block.getTopLeftCorner().first + j, block.getTopLeftCorner().second + i) ||
                 game_board.get(block.getTopLeftCorner().first + j, block.getTopLeftCorner().second + i))
                && block.get(j, i)) {
                game_board.putFinishedBlock(current_block, current_block.getTopLeftCorner());
                current_block = next_block;
                next_block = (BlockOnBoard(ColoredBlockFactory::get_colored_block()));
                return 0;
            }
            else if(current_block.getTopLeftCorner().second < 0){
                    std::cout << "GAME OVER!!!" << std::endl;
                    setGameOver();
                    return 0;
                }
        }
    }
    return 1;
}

bool GameState::getGameOver() {
    return gameOver;
}

void GameState::setGameOver() {
    gameOver = true;
}