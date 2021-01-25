//
// Created by Matt on 20/01/2021.
//

#include "rule_value.h"

rule_value::rule_value(char letter, int first, int second, std::string password) {
    this->letter = letter;
    this->first = first;
    this->second = second;
    this->password = password;
}