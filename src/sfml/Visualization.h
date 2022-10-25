//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_VISUALAIZATION_H
#define TETRIS_VISUALAIZATION_H

#include <memory>
#include <iostream>

#include "gameLogic/GameState.h"
#include "gameLogic/Factory/ColorFactory.h"

class Visualization {
private:
    std::shared_ptr<sf::RenderWindow> window;
    void render_field(int x, int y, sf::Color color);
    void render_field_next_block(int x, int y, sf::Color color);
    void print_texts(GameState &state, std::string username);
public:
    explicit Visualization(std::shared_ptr<sf::RenderWindow> window);
    void render(GameState &state, std::string username);
    void print_game_over(GameState &state);
    void print_start_game();
    void print_enter_nick(std::string username);

};

#endif //TETRIS_VISUALAIZATION_H
