//
// Created by mharc on 02.10.2022.
//

#include "ColorFactory.h"

sf::Color ColorFactory::get_random_color() {
    return available_colors[distr(rng)];
}

std::vector<sf::Color> ColorFactory::available_colors({
                                                              sf::Color(215,215,19),
                                                              sf::Color(16, 215, 16),
                                                              sf::Color(0, 0, 255),
                                                              sf::Color(255, 128, 0),
                                                              sf::Color(255, 0, 0),
                                                      });

std::mt19937 ColorFactory::rng(std::chrono::system_clock::now().time_since_epoch().count());

std::uniform_int_distribution<> ColorFactory::distr(0, ColorFactory::get_number_of_colors() - 1);

int ColorFactory::get_number_of_colors() {
    return static_cast<int>(available_colors.size());
}