// Created by Matt
// 17/01/2021

#include <iostream>
#include <fstream>
#include <string>
#include <set>

#include "result.h"

/**
 * Create a set of integers from the specified file.
 * @param filename Path of the file to parse.
 * @return Set of integers. Empty set if failed to parse.
 */
std::set<int> createSet(char* filename) {
    std::set<int> valueSet;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            valueSet.insert(std::stoi(line));
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();
    return valueSet;
}

/**
 * Find a matching pair of values that sum to target
 * @param values List of values
 * @param target target to sum to
 * @return 2 values and whether the search was successful
 */
result findValues(std::set<int>* values, int target) {
    for(int first : *values) {
        int second = target - first;
        if(values->find(second) != values->end()) {
            // Found a pair, return success
            return {true, second, first};
        }
    }
    return {false, 0, 0};
}

/**
 * Find a pair of values from a list that sum to a third value
 */
int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: main [file path] [value]" << std::endl;
        return 1;
    }

    std::set<int> values = createSet(argv[1]);
    int targetSum = std::stoi(argv[2]);
    result res = findValues(&values, targetSum);
    if(res.success) {
        std::cout << "Found pair: " << res.first << ", " << res.second << std::endl;
        std::cout << "Product: " << res.first * res.second << std::endl;
    }
    else{
        std::cout << "No values in list sum to " << targetSum << std::endl;
    }
}
