#include "SFML/Graphics.hpp"

#include <iostream>
#include <chrono>

#include "sfml/UserInput.h"
#include "sfml/Visualization.h"

int main() {
    auto window_ptr =
            std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDOWS_SIZE_X, WIDOWS_SIZE_Y), "SFML Tetris");
    UserInput user_input(window_ptr);
    Visualization vis(window_ptr);
    GameState game;

    while(window_ptr->isOpen()) {

        vis.print_start_game();

        auto input = user_input.get_position_of_clicked_mouse();
        if(game.in_range_start(input))
            break;
    }
    while(window_ptr->isOpen() && user_input.set_username()) {
        vis.print_enter_nick(user_input.get_username());
    }
    while (window_ptr->isOpen() && !game.get_game_over()){
        auto start_time = std::chrono::system_clock::now();

        // ******************* process input *******************
        auto input = user_input.get_new_input();
        for(auto i: input)
            std::cerr << i << std::endl;

        // ******************* update *******************
        game.update(input);

        // ******************* render *******************9
        vis.render(game, user_input.get_username());


        auto end_time = std::chrono::system_clock::now();
        auto spent = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        sf::sleep(sf::milliseconds(MS_PER_FRAME - spent));
    }
    while(window_ptr->isOpen()) {

        vis.print_game_over(game);

        auto input = user_input.get_position_of_clicked_mouse();

        if(game.in_range_exit(input))
            window_ptr->close();

        if(game.in_range_play_again(input)) {
            window_ptr->close();
            main();
        }
    }


}