//
// Created by mharc on 02.10.2022.
//

#ifndef TETRIS_COLORFACTORY_H
#define TETRIS_COLORFACTORY_H

#include "SFML/Graphics.hpp"

#include <random>     /* srand, rand */
#include <chrono>
#include <iostream>

class ColorFactory {
private:
    static std::vector<sf::Color> available_colors;
    static std::mt19937 rng;
    static std::uniform_int_distribution<> distr;

public:
    static int get_number_of_colors();
    static sf::Color get_random_color();

};


#endif //TETRIS_COLORFACTORY_H
