#include "SFML/Graphics.hpp"

#include "sfml/UserInput.h"
#include "sfml/Visualization.h"
#include "gameLogic/Run.h"
int main() {
    bool play = true;

    while(play) {
        auto window_ptr =
                std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDOWS_SIZE_X, WIDOWS_SIZE_Y), "SFML Tetris");
        UserInput user_input(window_ptr);
        Visualization vis(window_ptr);
        GameState game;

        start_screen(window_ptr, vis, user_input, game);
        username_screen(window_ptr, vis, user_input);
        game_screen(window_ptr, vis, user_input, game);
        play = game_over_screen(window_ptr, vis, user_input, game);

        window_ptr->close();
    }

}