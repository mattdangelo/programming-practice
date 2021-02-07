//
// Created by Matt on 7/02/2021.
//

#include <string>
#include <algorithm>

#include "utils.h"

/**
 * Remove carriage returns from the end of the string, if one exists
 * @param to_sanitize The string to sanitize
 * @return The sanitized string
 */
std::string utils::sanitize(std::string s) {
    if (s[s.length()-1] == '\r') {
        s.erase(s.length()-1);
    }
    return s;
}

std::string utils::stripFormatting(std::string s) {
    char to_remove[] = {'.', ','};
    for(char c : to_remove) {
        s.erase(std::remove(s.begin(), s.end(), c), s.end());
    }
    return s;
}

std::string utils::removeFromString(std::string str, const std::vector<std::string>& values) {
    for(const std::string& s : values) {
        std::string::size_type i = str.find(s);
        if (i != std::string::npos) {
            str.erase(i, str.length());
        }
    }
    return str;
}
