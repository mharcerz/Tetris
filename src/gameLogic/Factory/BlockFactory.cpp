//
// Created by mharc on 02.10.2022.
//

#include "BlockFactory.h"

int BlockFactory::get_number_of_patterns() {
    return static_cast<int>(available_patterns.size());
}

BlockPattern BlockFactory::get_random_pattern() {
    return BlockPattern(available_patterns[distr(rng)]);
}

std::mt19937 BlockFactory::rng(std::chrono::system_clock::now().time_since_epoch().count());

std::vector<std::vector<std::string>> BlockFactory::available_patterns({{
                                                                                "1000",
                                                                                "1000",
                                                                                "1000",
                                                                                "1000",
                                                                        },
                                                                        {
                                                                                "1100",
                                                                                "1100",
                                                                                "0000",
                                                                                "0000",
                                                                        }
                                                                       });

std::uniform_int_distribution<> BlockFactory::distr(0, BlockFactory::get_number_of_patterns() - 1);

