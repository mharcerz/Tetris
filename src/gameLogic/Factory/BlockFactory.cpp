//
// Created by mharc on 02.10.2022.
//

#include "BlockFactory.h"

std::vector<std::vector<std::string>> BlockFactory::available_patterns({{
                                                                                "0100",
                                                                                "0100",
                                                                                "0100",
                                                                                "0100",
                                                                        },
                                                                        {
                                                                                "0000",
                                                                                "0011",
                                                                                "0110",
                                                                                "0000",
                                                                        },
                                                                        {
                                                                                "0000",
                                                                                "0110",
                                                                                "0110",
                                                                                "0000",
                                                                        },
                                                                        {
                                                                                "0100",
                                                                                "0100",
                                                                                "0110",
                                                                                "0000",
                                                                        },
                                                                        {
                                                                                "0010",
                                                                                "0010",
                                                                                "0110",
                                                                                "0000",
                                                                        },
                                                                        {
                                                                                "0010",
                                                                                "0111",
                                                                                "0000",
                                                                                "0000",
                                                                        },
                                                                        {
                                                                                "0000",
                                                                                "0110",
                                                                                "0011",
                                                                                "0000",
                                                                        }
                                                                       });

int BlockFactory::get_number_of_patterns() {
    return static_cast<int>(available_patterns.size());
}

std::mt19937 BlockFactory::rng(std::chrono::system_clock::now().time_since_epoch().count());

std::uniform_int_distribution<> BlockFactory::distr(0, BlockFactory::get_number_of_patterns() - 1);

std::uniform_int_distribution<> BlockFactory::dist4(0, 3);

BlockPattern BlockFactory::get_random_pattern() {
    int r = dist4(rng);
    auto block = BlockPattern(available_patterns[distr(rng)]);
    for(int i = 0; i < r; i++)
        block.rotate();
    return block;
}


