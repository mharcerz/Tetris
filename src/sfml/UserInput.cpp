//
// Created by mharc on 01.10.2022.
//

#include "sfml/UserInput.h"


UserInput::UserInput(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {}

std::vector<Keys> UserInput::get_new_input() {
    std::vector<Keys> keys;
    sf::Event event;

    // Check for all the events that occured since the last call.
    while (window->pollEvent(event)) {
        //Handle events here

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
        }
    }
    return keys;
}

std::pair<int, int> UserInput::get_position_of_clicked_mouse() {

    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                return {event.mouseButton.x, event.mouseButton.y};
            }
        }

        if (event.type == sf::Event::EventType::Closed) {
            window->close();
            printf("event close");
        }

    }
}

int UserInput::set_username() {
    sf::Event event;
    while (window->pollEvent(event)) {

        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode < 128)
            {
                if(event.text.unicode == 13 && !username.empty())
                    return 0;
                if(event.text.unicode == 8 && !username.empty())
                    username.pop_back();
                else if(event.text.unicode != 8 && username.size() < 9)
                    username.push_back(static_cast<char>(event.text.unicode));

                return 1;
            }
        }
        if (event.type == sf::Event::EventType::Closed) {
            window->close();
            printf("event close");
        }
    }
    return 1;
}

std::string UserInput::get_username() {
    return username;
}