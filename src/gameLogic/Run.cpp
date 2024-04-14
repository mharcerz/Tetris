//
// Created by mharc on 26.10.2022.
//

#include "Run.h"

void start_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game) {
    while(window_ptr->isOpen()) {

        vis.print_start_game();

        auto input = user_input.get_position_of_clicked_mouse();
        if(game.in_range_start(input))
            break;
    }
}

void username_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input) {

    while(window_ptr->isOpen() && user_input.set_username())
        vis.print_enter_nick(user_input.get_username());
}

void game_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game)
{
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
}

bool game_over_screen(std::shared_ptr<sf::RenderWindow> window_ptr, Visualization &vis, UserInput &user_input, GameState &game) {
    while(window_ptr->isOpen()) {

        vis.print_game_over(game);

        auto input = user_input.get_position_of_clicked_mouse();

        if(game.in_range_exit(input))
            return false;

        if(game.in_range_play_again(input))
            return true;
    }
}