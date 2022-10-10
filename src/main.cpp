#include "SFML/Graphics.hpp"

#include <iostream>
#include <random>
#include <chrono>
#include <thread>

#include "sfml/UserInput.h"
#include "gameLogic/Factory/ColorFactory.h"
#include "gameLogic/Factory/BlockFactory.h"
#include "gameLogic/BlockOnBoard.h"
#include "sfml/Visualization.h"

void elo()
{
    std::cout << "Elo" << std::endl;
}
int main(int argc, char ** argv) {
    auto window_ptr =
            std::make_shared<sf::RenderWindow>(sf::VideoMode(WIDOWS_SIZE_X, WIDOWS_SIZE_Y), "SFML Tetris");
    UserInput userInput(window_ptr);
    Visualization vis(window_ptr);
    GameState game;

//    BlockPattern blockPattern = BlockFactory::get_random_pattern();
//    blockPattern.print_matrix();
    // A Clock starts counting as soon as it's created
//    sf::Color color(sf::Color::Red);
//sf::Color col = ColorFactory::get_random_color();
// ToDo: first frame before?
    int timer = 0;

    while (window_ptr->isOpen()){
        auto start_time = std::chrono::system_clock::now();

        // ******************* process input *******************

        auto input = userInput.get_new_input();
        for(auto i: input) {
            std::cerr << i << std::endl;
        }
        // TODO: process input
        // ******************* update *******************
        // TODO: update
        timer++;
        timer = game.update(input, timer);

        // ******************* render *******************
        vis.render(game);





        auto end_time = std::chrono::system_clock::now();
        auto spent = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        sf::sleep(sf::milliseconds(MS_PER_FRAME - spent));

    }

}