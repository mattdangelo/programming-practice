//
// Created by Matt on 7/02/2021.
//

#include <string>

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
