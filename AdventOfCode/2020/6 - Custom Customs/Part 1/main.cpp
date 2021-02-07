//
// Created by Matt on 4/02/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>

#include "../../Shared/utils.h"

/**
 * Count the number of unique yes answered questions in a group
 * @param lines The group of answers
 * @return The number of unique yes answers
 */
int countGroup(const std::vector<std::string>& lines) {
    std::set<char> yes_answered;
    for(const std::string& line : lines) {
        for(char c : line) {
            yes_answered.insert(c);
        }
    }
    return yes_answered.size();
}

/**
 * Return the sum of the counts of the different groups
 * @param filename The name of the file which contains the answers to the boarding groups
 * @return The sum of the counts
 */
int sumOfCounts(char* filename) {
    int count = 0;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::vector<std::string> lines;
        while(std::getline(file, line)) {
            if(line.length() == 1) {
                count += countGroup(lines);
                lines.clear();
            }
            else {
                lines.push_back(utils::sanitize(line));
            }
        }
        lines.push_back(utils::sanitize(line));
        count += countGroup(lines);
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();
    return count;
}

/**
 * Print the sum of the counts of 'yes' responses
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << sumOfCounts(argv[1]) << std::endl;
}