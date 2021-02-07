//
// Created by Matt on 20/01/2021.
//

#include "rule_value.h"

rule_value::rule_value(char letter, int min, int max, std::string password) {
    this->letter = letter;
    this->min = min;
    this->max = max;
    this->password = std::move(password);
}