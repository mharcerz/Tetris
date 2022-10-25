//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_GAMESTATE_H
#define TETRIS_GAMESTATE_H

#include "SFML/Graphics.hpp"

#include "sfml/UserInput.h"
#include "GameBoard.h"

enum BlockMovement {move_left, move_right, move_down, rotate};

class GameState {
private:
    int timer;
    int sum_of_cleared_rows;
    int move_down_speed;
    bool game_over;
    GameBoard game_board;
    BlockOnBoard current_block;
    BlockOnBoard next_block;
    void set_game_over();
    bool should_i_put_finished_block(BlockOnBoard block);
    bool is_it_correct(BlockOnBoard block);
    void move(BlockMovement move);
    void setDownSpeed(int cleared_rows);
public:
    [[nodiscard]] bool get_game_over() const;
    GameState();
    int get_score();
    void update(const std::vector<Keys>& input);
    bool in_range_exit(std::pair <int, int> clicked_position);
    bool in_range_start(std::pair <int, int> clicked_position);
    bool in_range_play_again(std::pair <int, int> clicked_position);
    /*
     * returns field color based on game_board and current_block
     */
    sf::Color field_color(int x, int y);
    sf::Color field_color_next_block(int x, int y);
};

#endif //TETRIS_GAMESTATE_H
