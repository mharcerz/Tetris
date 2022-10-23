//
// Created by mharc on 01.10.2022.
//

#include "ColoredBlockFactory.h"

BlockWithColor ColoredBlockFactory::get_colored_block() {
    sf::Color col = ColorFactory::get_random_color();
    BlockPattern block = BlockFactory::get_random_pattern();
    return BlockWithColor(block, col);
}