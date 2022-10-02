//
// Created by mharc on 01.10.2022.
//

#include "sfml/UserInput.h"

#include <utility>

UserInput::UserInput(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {} //  this->window = window;
//UserInput::UserInput() {} //  this->window = window;

std::vector<Keys> UserInput::get_new_input() {
    std::vector<Keys> keys;
    sf::Event event;

    // Check for all the events that occured since the last call.
    while (window->pollEvent(event)) {
        //Handle events here

        // TODO: move outside
        if (event.type == sf::Event::EventType::Closed) {
            window->close();
            printf("event close");
        }

        if (event.type == sf::Event::EventType::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                printf("Space\n");
                keys.push_back(space);
            } else if (event.key.code == sf::Keyboard::Up) {
                printf("Page up\n");
                keys.push_back(up);
            } else if (event.key.code == sf::Keyboard::Down) {
                printf("Page down\n");
                keys.push_back(down);
            } else if (event.key.code == sf::Keyboard::Left) {
                printf("Page left\n");
                keys.push_back(left);
            } else if (event.key.code == sf::Keyboard::Right) {
                printf("Page right\n");
                keys.push_back(right);
            }

//        if(sf::Keyboard::isKeyPressed(window.pollEvent(event)))
//            while (window.pollEvent(event));

        }
    }
    return keys;
}