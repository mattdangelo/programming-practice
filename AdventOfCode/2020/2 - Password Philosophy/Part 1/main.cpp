// Created by Matt
// 17/01/2021

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "rule_value.h"

/**
 * Create a set of rule_values from the specified file.
 * @param filename Path of the file to parse.
 * @return Set of rule_values.
 */
std::vector<rule_value> createRuleValueSet(char* filename) {
    std::vector<rule_value> ruleValueSet;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::string buf;
            std::stringstream ss(line);
            std::vector<std::string> tokens;

            while (ss >> buf) {
                tokens.push_back(buf);
            }

            if(tokens.size() != 3) {
                std::cerr << "Failed to parse line: \"" << line << "\""<< std::endl;\
                exit(1);
            }
            // At this point, tokens has 3 elements - a min / max, ("2-4"), a letter followed by a colon ("e:"), and the
            // password ("asdasedrgs")
            int min = std::stoi(tokens[0].substr(0, tokens[0].find('-')));
            tokens[0].erase(0, tokens[0].find('-') + 1);
            int max = std::stoi(tokens[0]);

            // The letter is the first character of the second token (which is of the form "c:")
            char letter = tokens[1][0];

            std::string password = tokens[2];

            ruleValueSet.emplace_back(letter, min, max, password);
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
    }
    file.close();
    return ruleValueSet;
}

/**
 * Print the total number of valid passwords given an input file
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::vector<rule_value> rule_values = createRuleValueSet(argv[1]);
    int valid_passwords = 0;
    for(rule_value rv : rule_values) {
        size_t count = std::count(rv.password.begin(), rv.password.end(), rv.letter);
        if(count >= rv.min && count <= rv.max) {
            valid_passwords++;
        }
    }

    std::cout << valid_passwords << std::endl;
}
