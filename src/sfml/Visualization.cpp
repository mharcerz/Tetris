//
// Created by mharc on 01.10.2022.
//

#include "sfml/Visualization.h"
#include "gameLogic/Factory/ColorFactory.h"

Visualization::Visualization(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {}

void Visualization::render(GameState &state) {
    window->clear();
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(BOARD_SIZE_X, BOARD_SIZE_Y));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(X_OFFSET_BOARD, Y_OFFSET_BOARD);
    window->draw(rectangle);

    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for( int j = 0; j < BOARD_HEIGHT; j++)
        {
                render_field(i, j, state.fieldColor(i, j));
        }
    }

    window->display();

}

void Visualization::render_field(int x, int y, sf::Color color) {
    if(color == sf::Color::Black)
        return;
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(PIXELS_PER_FIELD, PIXELS_PER_FIELD));
    rectangle.setFillColor(color);
    rectangle.setPosition(X_OFFSET_BOARD + x * PIXELS_PER_FIELD, Y_OFFSET_BOARD + y * PIXELS_PER_FIELD);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(1);

    window->draw(rectangle);
}
