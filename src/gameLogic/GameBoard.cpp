//
// Created by mharc on 09.10.2022.
//

#include "GameBoard.h"

GameBoard::GameBoard() {
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            color[i][j] = sf::Color::Black;
        }
    }
    score = 0;
}

void GameBoard::add_to_score(int value) {
    score += value;
}

int GameBoard::get_score() {
    return score;
}

sf::Color GameBoard::field_color(int x, int y) {
    if (get(x, y))
        return color[x][y];
    else
        return sf::Color::Black;
}

bool GameBoard::get(int x, int y) {
    if (y < 0) return false;
    return matrix.get(x, y);
}

void GameBoard::put_finished_block(BlockOnBoard block, std::pair<int, int> top_left_corner) {

    for (int i = top_left_corner.second; i < top_left_corner.second + MAX_PIECE_HEIGHT; i++) {
        for (int j = top_left_corner.first; j < top_left_corner.first + MAX_PIECE_WIDTH; j++) {
            sf::Color color;

            color = block.field_color(j, i);
            if (color != sf::Color::Black) {
                this->color[j][i] = color;
                matrix.set_piece_here(j, i);
            }
        }
    }
    add_to_score(POINTS_FOR_PUT_BLOCK);
}

int GameBoard::process_after_move() {

    int n = -1;
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        if (is_row_full_of_blocks(i)) {
            clear_rows(i);
            n++;
        }
    }
    if(n >= 0)
        add_to_score(pow(2, n) * POINTS_FOR_CLEAR_ROW);
    return n + 1;
}

bool GameBoard::is_row_full_of_blocks(int i) {
    for (int j = 0; j < BOARD_WIDTH; j++)
        if (!get(j, i))
            return false;
    return true;
}

void GameBoard::clear_rows(int i) {
    for (; i > 0; i--) {
        for(int j = 0; j < BOARD_WIDTH; j++) {
            color[j][i] = color[j][i - 1];
            if(matrix.get(j, i - 1))
                matrix.set_piece_here(j, i);
            else
                matrix.remove_piece_here(j, i);
        }
    }
}