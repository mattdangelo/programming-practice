//
// Created by Matt on 20/01/2021.
//

#ifndef ADVENT_OF_CODE_RULE_VALUE_H
#define ADVENT_OF_CODE_RULE_VALUE_H

#include <string>

class rule_value {
public:
    char letter;
    int first;
    int second;
    std::string password;
    rule_value(char, int, int, std::string);
};

#endif //ADVENT_OF_CODE_RULE_VALUE_H
