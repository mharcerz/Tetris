//
// Created by mharc on 01.10.2022.
//

#include "sfml/Visualization.h"

Visualization::Visualization(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {}

void Visualization::render(GameState &state) {
    window->clear();
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(BOARD_SIZE_X, BOARD_SIZE_Y));
    rectangle.setFillColor(sf::Color(5,5,5));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(X_OFFSET_BOARD, Y_OFFSET_BOARD);
    window->draw(rectangle);

    sf::RectangleShape rectangle_next_block;
    rectangle_next_block.setSize(sf::Vector2f(BOARD_SIZE_NEXT_BLOCK_X, BOARD_SIZE_NEXT_BLOCK_Y));
    rectangle_next_block.setOutlineColor(sf::Color::White);
    rectangle_next_block.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle_next_block.setPosition(X_OFFSET_BOARD_NEXT_BLOCK, Y_OFFSET_BOARD_NEXT_BLOCK);
    window->draw(rectangle_next_block);

    for(int i = 0; i < BOARD_WIDTH; i++)
    {
        for( int j = 0; j < BOARD_HEIGHT; j++)
        {
                render_field(i, j, state.field_color(i, j));
        }
    }

    for(int i = 0; i < MAX_PIECE_WIDTH; i++)
    {
        for( int j = 0; j < MAX_PIECE_HEIGHT; j++)
        {
            render_field_next_block(i, j, state.field_color_next_block(i, j));
        }
    }
    print_texts(state);
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

void Visualization::render_field_next_block(int x, int y, sf::Color color) {

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(PIXELS_PER_FIELD, PIXELS_PER_FIELD));
    rectangle.setFillColor(color);
    rectangle.setPosition(X_OFFSET_BOARD_NEXT_BLOCK + x * PIXELS_PER_FIELD, Y_OFFSET_BOARD_NEXT_BLOCK + y * PIXELS_PER_FIELD);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(1);

    window->draw(rectangle);
}

void Visualization::print_texts(GameState &state) {

    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Error" << std::endl;

    text.setFont(font);
    text.setString("NEXT BLOCK:");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(X_OFFSET_BOARD_NEXT_BLOCK, Y_OFFSET_BOARD_NEXT_BLOCK - 30);
    window->draw(text);

    text.setString("Score:");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(X_OFFSET_BOARD_NEXT_BLOCK, Y_OFFSET_BOARD_NEXT_BLOCK + 200);
    window->draw(text);

    text.setString(std::to_string(state.get_score()));
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(X_OFFSET_BOARD_NEXT_BLOCK + 45, Y_OFFSET_BOARD_NEXT_BLOCK + 240);
    window->draw(text);
}