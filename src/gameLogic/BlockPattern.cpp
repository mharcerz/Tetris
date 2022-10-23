//
// Created by mharc on 10.10.2022.
//

#include "BlockPattern.h"

BlockPattern::BlockPattern(std::vector<std::string> pattern) : BoolMatrix<MAX_PIECE_WIDTH, MAX_PIECE_HEIGHT>(std::move(pattern)) {}
