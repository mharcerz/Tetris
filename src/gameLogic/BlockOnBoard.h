//
// Created by mharc on 01.10.2022.
//


#ifndef TETRIS_BLOCKONBOARD_H
#define TETRIS_BLOCKONBOARD_H

#include "GameConstants.h"
#include "BlockWithColor.h"

class BlockOnBoard : public BlockWithColor {
private:
    /*
     * top left corner of matrix 4x4 on a game board
     */
    std::pair<int, int> top_left_corner;
    /*
     * distance of occupied between y value of first colored block and start of matrix<4,4>
     */
    std::pair<int, int> top_of_bool_matrix;
    int height;
    void set_height_and_top_of_bool_matrix();
    void set_top_of_bool_matrix(int x, int y);
    void set_height(std::pair<int, int> top_and_down_y);
    std::pair<int, int> get_top_of_bool_matrix();
    int get_height();
public:
    BlockOnBoard(BlockWithColor block);
    BlockOnBoard get_rotated();
    BlockOnBoard get_moved_down();
    BlockOnBoard get_moved_right();
    BlockOnBoard get_moved_left();

    /*
     * returns color of the field for this Block
     * coordinates are in respect to the whole Board
     */
    sf::Color field_color(int x, int y);
    bool is_it_on_the_board(int x, int y);
    void set_top_left_corner(int x, int y);
    std::pair<int, int> get_top_left_corner();
};

#endif //TETRIS_BLOCKONBOARD_H
