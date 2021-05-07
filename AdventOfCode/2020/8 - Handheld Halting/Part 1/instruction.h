//
// Created by Matt on 7/05/2021.
//

#ifndef ADVENT_OF_CODE_INSTRUCTION_H
#define ADVENT_OF_CODE_INSTRUCTION_H

#include <string>

struct instruction {
    bool executed;
    std::string instruction;
    int value;
};

#endif //ADVENT_OF_CODE_INSTRUCTION_H
