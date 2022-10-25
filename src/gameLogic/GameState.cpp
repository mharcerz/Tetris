//
// Created by mharc on 01.10.2022.
//

#include "GameState.h"
#include "gameLogic/Factory/ColoredBlockFactory.h"

GameState::GameState() : game_board(),
                         current_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())),
                         next_block(BlockOnBoard(ColoredBlockFactory::get_colored_block())) {
    timer = 1;
    game_over = false;
    move_down_speed = 10;
    sum_of_cleared_rows = 0;
}

sf::Color GameState::field_color(int x, int y) {
    if (game_board.field_color(x, y) != sf::Color::Black) {
        return game_board.field_color(x, y);
    }
    return current_block.field_color(x, y);
}

sf::Color GameState::field_color_next_block(int x, int y) {
    if (next_block.in_range(x, y) && next_block.get(x, y)) {
        return next_block.get_color();
    }
    return {5, 5, 5};
}

void GameState::update(const std::vector<Keys> &input) {
    for (auto key: input) {
        if (key == Keys::up || key == Keys::space)
            move(BlockMovement::rotate);
        else if (key == Keys::left)
            move(BlockMovement::move_left);
        else if (key == Keys::right)
            move(BlockMovement::move_right);
        else if (key == Keys::down) {
            move(BlockMovement::move_down);
            timer = 1;
        }
    }

    setDownSpeed(game_board.process_after_move());

    if (timer % move_down_speed == 0) {
        move(BlockMovement::move_down);
        timer = 1;
    } else
        timer++;
}

void GameState::move(BlockMovement move) {
    switch (move) {
        case move_left: {
            BlockOnBoard moved_left(current_block.get_moved_left());
            if (is_it_correct(moved_left)) {
                current_block = moved_left;
            }
            break;
        }
        case move_right: {
            BlockOnBoard moved_right(current_block.get_moved_right());
            if (is_it_correct(moved_right)) {
                current_block = moved_right;
            }
            break;
        }
        case move_down: {
            BlockOnBoard moved_down(current_block.get_moved_down());
            if (is_it_correct(moved_down)) {
                current_block = moved_down;
            } else if (should_i_put_finished_block(moved_down)) {
                game_board.put_finished_block(current_block, current_block.get_top_left_corner());
                current_block = next_block;
                next_block = (BlockOnBoard(ColoredBlockFactory::get_colored_block()));
            } else { //if(current_block.get_top_left_corner().second < 0)
                //ToDo: call game_over() function
                std::cout << "GAME OVER!!!" << std::endl;
                set_game_over();
            }
            break;
        }
        case rotate: {
            BlockOnBoard rotated(current_block.get_rotated());
            if (is_it_correct(rotated)) {
                current_block = rotated;
            }
            break;
        }
    }
}

bool GameState::is_it_correct(BlockOnBoard block) {
    for (int i = 0; i < MAX_PIECE_HEIGHT; i++) {
        for (int j = 0; j < MAX_PIECE_WIDTH; j++) {

            if ((game_board.get(block.get_top_left_corner().first + j, block.get_top_left_corner().second + i) &&
                 block.get(j, i)) ||
                (block.get(j, i) && !BlockOnBoard::is_it_on_the_board(block.get_top_left_corner().first + j,
                                                                      block.get_top_left_corner().second + i)))
                return false;
        }
    }
    return true;
}

bool GameState::should_i_put_finished_block(BlockOnBoard block) {
    for (int i = 0; i < MAX_PIECE_HEIGHT; i++) {
        for (int j = 0; j < MAX_PIECE_WIDTH; j++) {
            if ((!BlockOnBoard::is_it_on_the_board(block.get_top_left_corner().first + j,
                                                   block.get_top_left_corner().second + i) ||
                 game_board.get(block.get_top_left_corner().first + j, block.get_top_left_corner().second + i))
                && block.get(j, i)) {
                return true;
            } else if (current_block.get_top_left_corner().second < 0) {
                return false;
            }
        }
    }
    return false;
}

bool GameState::get_game_over() const {
    return game_over;
}

void GameState::set_game_over() {
    game_over = true;
}

int GameState::get_score() {
    return game_board.get_score();
}

void GameState::setDownSpeed(int cleared_rows) {

    if (cleared_rows) {
        sum_of_cleared_rows += cleared_rows;
        if (sum_of_cleared_rows % 10 == 0)
            move_down_speed--;
    }
}

bool GameState::in_range_exit(std::pair<int, int> clicked_position) {
    return clicked_position.first >= 256 &&
           clicked_position.first <= 356 &&
           clicked_position.second >= 475 &&
           clicked_position.second <= 525;
}

bool GameState::in_range_start(std::pair<int, int> clicked_position) {
    return clicked_position.first >= 240 &&
           clicked_position.first <= 370 &&
           clicked_position.second >= 530 &&
           clicked_position.second <= 580;
}

bool GameState::in_range_play_again(std::pair<int, int> clicked_position) {
    return clicked_position.first >= 210 &&
           clicked_position.first <= 410 &&
           clicked_position.second >= 370 &&
           clicked_position.second <= 430;
}