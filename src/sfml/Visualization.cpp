//
// Created by mharc on 01.10.2022.
//

#include "sfml/Visualization.h"

Visualization::Visualization(std::shared_ptr<sf::RenderWindow> window) : window(std::move(window)) {}

void Visualization::render(GameState &state, std::string username) {
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
    print_texts(state, username);
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

void Visualization::print_texts(GameState &state, std::string username) {

    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Error" << std::endl;

    text.setFont(font);

    text.setString(username);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Italic);
    text.setPosition(X_OFFSET_BOARD_NEXT_BLOCK, Y_OFFSET_BOARD_NEXT_BLOCK - 90);
    window->draw(text);

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

    text.setString("Powered by:");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    text.setString("Michal Holubowicz");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color(0, 94, 255));
    text.setPosition(290, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);
}

void Visualization::print_game_over(GameState &state) {
    window->clear();

    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Error" << std::endl;

    text.setFont(font);
    text.setString("GAME OVER!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(150, 180);
    window->draw(text);

    text.setString("Your Score:");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(220, 280);
    window->draw(text);

    text.setString(std::to_string(state.get_score()));
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(375, 280);
    window->draw(text);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(200, 50));
    rectangle.setFillColor(sf::Color(10,10,10));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(210, 370);
    window->draw(rectangle);

    text.setString("PLAY AGAIN!");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(233, 378);
    window->draw(text);

    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color(10,10,10));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(256, 475);
    window->draw(rectangle);

    text.setString("EXIT");
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(277, 482);
    window->draw(text);

    text.setString("Powered by:");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    text.setString("Michal Holubowicz");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color(0, 94, 255));
    text.setPosition(290, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);


    sf::Texture imageSource;
    if (!imageSource.loadFromFile("../src/pictures/picture_game_over.png"))
        std::cout << "Error" << std::endl;

    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);
    imageSprite.setPosition(-18, -30);
    imageSprite.setScale(2, 1.8);
    window->draw(imageSprite);

    window->display();
}

void Visualization::print_start_game() {

    window->clear();

    sf::Texture imageSource;
    if (!imageSource.loadFromFile("../src/pictures/picture_start_game.png"))
        std::cout << "Error" << std::endl;

    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);
    imageSprite.setPosition(3, 7);
    imageSprite.setScale(1.2, 1.39);
    window->draw(imageSprite);

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Error" << std::endl;
    text.setFont(font);

    text.setString("T");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(125, 80);
    window->draw(text);

    text.setString("E");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Yellow);
    text.setPosition(185, 80);
    window->draw(text);

    text.setString("T");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(253, 80);
    window->draw(text);

    text.setString("R");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(315, 80);
    window->draw(text);

    text.setString("I");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Green);
    text.setPosition(388, 80);
    window->draw(text);

    text.setString("S");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Cyan);
    text.setPosition(415, 80);
    window->draw(text);

    if (!imageSource.loadFromFile("../src/pictures/picture_start_game_v2.png"))
        std::cout << "Error" << std::endl;

    imageSprite.setTexture(imageSource);
    imageSprite.setPosition(230, 415);
    imageSprite.setScale(0.3, 0.3);
    window->draw(imageSprite);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(130, 50));
    rectangle.setFillColor(sf::Color(10,10,10));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(240, 530);
    window->draw(rectangle);


    text.setString("PLAY!");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(263, 535);
    window->draw(text);


    text.setString("Powered by:");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    text.setString("Michal Holubowicz");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color(0, 94, 255));
    text.setPosition(290, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    window->display();
}

void Visualization::print_enter_nick(std::string username) {

    window->clear();

    sf::Texture imageSource;
    if (!imageSource.loadFromFile("../src/pictures/picture_start_game.png"))
        std::cout << "Error" << std::endl;

    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);
    imageSprite.setPosition(3, 7);
    imageSprite.setScale(1.2, 1.39);
    window->draw(imageSprite);

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("../src/fonts/arial.ttf"))
        std::cout << "Error" << std::endl;
    text.setFont(font);


    text.setString("Enter your Nick:");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(205, 290);
    window->draw(text);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(250, 50));
    rectangle.setFillColor(sf::Color(30,30,30));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(BORDER_LINE_THICKNESS);
    rectangle.setPosition(188, 340);
    window->draw(rectangle);

    text.setString(username);
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::White);
    text.setPosition(194, 346);
    window->draw(text);

    text.setString("Powered by:");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(200, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    text.setString("Michal Holubowicz");
    text.setCharacterSize(15);
    text.setFillColor(sf::Color(0, 94, 255));
    text.setPosition(290, 720);
    text.setStyle(sf::Text::Italic);
    window->draw(text);

    window->display();
}
