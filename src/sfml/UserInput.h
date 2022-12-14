//
// Created by mharc on 01.10.2022.
//

#ifndef TETRIS_USERINPUT_H
#define TETRIS_USERINPUT_H

#include <memory>
#include <iostream>
#include "SFML/Graphics.hpp"

enum Keys {
    space, left, right, up, down
};

class UserInput {
private:
    std::shared_ptr<sf::RenderWindow> window;
    std::string username;
public:
    explicit UserInput(std::shared_ptr<sf::RenderWindow>);
    /*
     * Returns list of keys that were clicked after previous call
     * Filters keys only to watched ones
     * Keeps chronological order and returns only first click of each key
     */
    std::vector<Keys> get_new_input();
    std::pair<int, int> get_position_of_clicked_mouse();
    std::string get_username();
    int set_username();

};

#endif //TETRIS_USERINPUT_H
