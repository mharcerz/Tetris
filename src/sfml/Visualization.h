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
    void print_texts(GameState &state);
public:
    explicit Visualization(std::shared_ptr<sf::RenderWindow> window);
    void render(GameState &state);
};

#endif //TETRIS_VISUALAIZATION_H
