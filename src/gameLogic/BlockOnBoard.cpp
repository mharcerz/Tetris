//
// Created by mharc on 01.10.2022.
//

#include "gameLogic/BlockOnBoard.h"


/*
 * The default position of the lower end of the block is on row -1 in the middle
 */
BlockOnBoard::BlockOnBoard(BlockWithColor block) : BlockWithColor(block) {

    set_height_and_top_of_bool_matrix();
    set_top_left_corner(BOARD_WIDTH / 2 - MAX_PIECE_WIDTH / 2, -get_top_of_bool_matrix().second - get_height());
}

BlockOnBoard BlockOnBoard::get_rotated() {
    BlockOnBoard result(*this);
    result.rotate();
    return result;
}

BlockOnBoard BlockOnBoard::get_moved_down() {
    BlockOnBoard result(*this);
    result.set_top_left_corner(result.get_top_left_corner().first, result.get_top_left_corner().second + 1);
    return result;
}

BlockOnBoard BlockOnBoard::get_moved_right() {
    BlockOnBoard result(*this);
    result.set_top_left_corner(result.get_top_left_corner().first + 1, result.get_top_left_corner().second);
    return result;
}

BlockOnBoard BlockOnBoard::get_moved_left() {
    BlockOnBoard result(*this);
    result.set_top_left_corner(result.get_top_left_corner().first - 1, result.get_top_left_corner().second);
    return result;
}

sf::Color BlockOnBoard::field_color(int x, int y) {
    int block_x = x - get_top_left_corner().first;
    int block_y = y - get_top_left_corner().second;

    if (in_range(block_x, block_y) && get(block_x, block_y)) {
        return get_color();
    }
    return sf::Color::Black;
}

bool BlockOnBoard::is_it_on_the_board(int x, int y) {

    return x >= 0 && x < BOARD_WIDTH && y >= -4 && y < BOARD_HEIGHT;
}

void BlockOnBoard::set_height_and_top_of_bool_matrix() {
    std::pair<int, int> topAndDownY = get_top_and_down_y();
    set_height(topAndDownY);
    std::pair<int, int> leftAndRightX = get_left_and_right_x();
    set_top_of_bool_matrix(leftAndRightX.first, topAndDownY.first);
}

void BlockOnBoard::set_top_left_corner(int x, int y) {
    top_left_corner.first = x;
    top_left_corner.second = y;
}

void BlockOnBoard::set_top_of_bool_matrix(int x, int y) {
    top_of_bool_matrix.first = x;
    top_of_bool_matrix.second = y;
}

void BlockOnBoard::set_height(std::pair<int, int> top_and_down_y) {
    height = top_and_down_y.second - top_and_down_y.first + 1;
}

std::pair<int, int> BlockOnBoard::get_top_left_corner() {
    return top_left_corner;
}

std::pair<int, int> BlockOnBoard::get_top_of_bool_matrix() {
    return top_of_bool_matrix;
}

int BlockOnBoard::get_height() const {
    return height;
}
