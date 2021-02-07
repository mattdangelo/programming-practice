//
// Created by Matt on 7/02/2021.
//

#ifndef ADVENT_OF_CODE_UTILS_H
#define ADVENT_OF_CODE_UTILS_H

#include <string>
#include <vector>

class utils {
public:
    static std::string sanitize(std::string);
    static std::string stripFormatting(std::string);
    static std::string removeFromString(std::string, const std::vector<std::string>&);
};


#endif //ADVENT_OF_CODE_UTILS_H
