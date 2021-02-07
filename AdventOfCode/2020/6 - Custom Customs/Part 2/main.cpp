//
// Created by Matt on 7/02/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

/**
 * Remove carriage returns from the end of the string, if one exists
 * @param to_sanitize The string to sanitize
 * @return The sanitized string
 */
std::string sanitize(std::string to_sanitize) {
    if (to_sanitize[to_sanitize.length()-1] == '\r') {
        to_sanitize.erase(to_sanitize.length()-1);
    }
    return to_sanitize;
}

/**
 * Count the number of all yes answered questions in a group
 * @param lines The group of answers
 * @return The number of unique yes answers
 */
int countGroup(const std::vector<std::string>& lines) {
    int total = 0;
    std::map<char, int> value_map;
    for(const std::string& line : lines) {
        for(char c : line) {
            if (value_map.count(c)) {
                value_map[c]++;
            }
            else {
                value_map[c] = 1;
            }
        }
    }

    std::map<char, int>::iterator it;
    int num_of_groups = lines.size();
    for(it = value_map.begin(); it != value_map.end(); it++) {
        if (it->second == num_of_groups) {
            total++;
        }
    }
    return total;
}

/**
 * Return the sum of the counts of the different groups for which each member answered 'yes'
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
                lines.push_back(sanitize(line));
            }
        }
        lines.push_back(sanitize(line));
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
 * Return the sum of the counts of 'yes' responses
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << sumOfCounts(argv[1]) << std::endl;
}