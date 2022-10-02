//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_VISUALAIZATION_H
#define TETRIS_VISUALAIZATION_H

#include <memory>

#include "SFML/Graphics.hpp"
#include "gameLogic/GameState.h"

class Visualization {
private:
    std::shared_ptr<sf::RenderWindow> window;
public:
    Visualization(std::shared_ptr<sf::RenderWindow> window);

    /*
     * TODO: need to figure out how to pass big structure as GameState
     */
    void render(GameState &state);
};


#endif //TETRIS_VISUALAIZATION_H
