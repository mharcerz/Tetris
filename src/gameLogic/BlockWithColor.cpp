//
// Created by mharc on 10.10.2022.
//

#include "BlockWithColor.h"

BlockWithColor::BlockWithColor(BlockPattern pattern, sf::Color color) : BlockPattern(pattern), color(color) {}

sf::Color BlockWithColor::get_color() {
    return color;
}