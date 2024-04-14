//
// Created by mharc on 26.10.2022.
//

#ifndef TETRIS_RUN_H
#define TETRIS_RUN_H

#include "SFML/Graphics.hpp"

#include <iostream>
#include <chrono>

#include "sfml/UserInput.h"
#include "sfml/Visualization.h"

void start_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game);

void username_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input);

void game_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game);

bool game_over_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game);

#endif //TETRIS_RUN_H
