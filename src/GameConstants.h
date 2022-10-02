//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_GAMECONSTANTS_H
#define TETRIS_GAMECONSTANTS_H



const int X_OFFSET_BOARD = 20;
const int Y_OFFSET_BOARD = 20;
const int BORDER_LINE_THICKNESS = 2;
const int PIXELS_PER_FIELD = 35;

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;

const int BOARD_SIZE_X = BOARD_WIDTH * PIXELS_PER_FIELD;
const int BOARD_SIZE_Y = BOARD_HEIGHT * PIXELS_PER_FIELD;

const int INFO_AREA_Y = 250;

const int WIDOWS_SIZE_X = X_OFFSET_BOARD + BOARD_SIZE_X + INFO_AREA_Y;
const int WIDOWS_SIZE_Y = Y_OFFSET_BOARD * 2 + BOARD_SIZE_Y;






const int MAX_PIECE_WIDTH = 4;
const int MAX_PIECE_HEIGHT = 4;

const int MS_PER_FRAME = 100;

#endif //TETRIS_GAMECONSTANTS_H
