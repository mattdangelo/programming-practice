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
            // At this point, tokens has 3 elements - a first / second value, ("2-4"), a letter followed by a colon
            // ("e:"), and the password ("asdasedrgs")
            int first = std::atoi(tokens[0].substr(0, tokens[0].find('-')).c_str());
            tokens[0].erase(0, tokens[0].find('-') + 1);
            int second = std::atoi(tokens[0].c_str());

            // The letter is the first character of the second token (which is of the form "c:")
            char letter = tokens[1][0];

            std::string password = tokens[2];

            ruleValueSet.emplace_back(letter, first, second, password);
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
    }
    file.close();
    return ruleValueSet;
}

/**
 * Return the total number of valid passwords given an input file
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::vector<rule_value> rule_values = createRuleValueSet(argv[1]);
    int valid_passwords = 0;
    for(rule_value rv : rule_values) {
        int count = 0;

        // Strings are indexed starting from 1, to we subtract 1 from the first / second values
        if(rv.password[rv.first - 1] == rv.letter) {
            count++;
        }

        if(rv.password[rv.second - 1] == rv.letter) {
            count++;
        }

        if(count == 1) {
            valid_passwords++;
        }
    }

    std::cout << valid_passwords << std::endl;
}
