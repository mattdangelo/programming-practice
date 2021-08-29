//
// Created by Matt on 29/08/2021.
//

#include <iostream>
#include <fstream>
#include <deque>
#include <set>
#include <vector>

/**
 * Return the min and max values from the contiguous range summing to the target value
 * @param input_vector the input value vector
 * @param target_value the target sum value
 * @return a std::pair containing the min and max values in the range
 */
std::pair<long, long> minMaxFromContiguousRange(std::vector<long> input_vector, unsigned long target_value) {
    for(int i = 0; i < input_vector.size(); i++) {
        unsigned long acc = input_vector.at(i);
        unsigned long local_min = acc;
        unsigned long local_max = acc;
        for(int j = i + 1; j < input_vector.size(); j++) {
            acc += input_vector.at(j);
            local_min = std::min<unsigned long>(local_min, input_vector.at(j));
            local_max = std::max<unsigned long>(local_max, input_vector.at(j));
            if (acc == target_value) {
                // Return the min / max values from the range
                return std::make_pair(local_min, local_max);
            }
            else if (acc > target_value) {
                break;
            }
        }
    }

    std::cerr << "No contiguous range detected. Exiting." << std::endl;
    exit(1);
}

/**
 * Create a vector of type long from the input file
 * @param filename the name of the input file
 * @return a vector of type long containing the values from the input file
 */
std::vector<long> createInputVector(char* filename) {
    std::ifstream file(filename);
    std::vector<long> input_vector;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            input_vector.push_back(stol(line));
        }
    }

    return input_vector;
}

/**
 * Print the first value in the sequence which does not adhere to the sum rule
 * @param filename The name of the file with the values to check
 * @return The first element that does not adhere to the sum rule
 */
unsigned long getFirstInvalidValue(std::vector<long> input_vector) {
    std::deque<long> previous_values;
    for(int i = 0; i < input_vector.size(); i++) {
        if(i < 25) {
            previous_values.push_back(input_vector.at(i));
        }
        else {
            long to_check = input_vector.at(i);
            std::set<unsigned long> previous_25_set = std::set<unsigned long>(previous_values.begin(), previous_values.end());
            // Do the value check
            bool found = false;

            for(long previous_value : previous_values) {
                if(previous_25_set.find(to_check - previous_value) != previous_25_set.end()) {
                    found = true;
                    break;
                }
            }

            if(found) {
                // Push the value we just checked onto the queue and pop off the first element
                previous_values.push_back(to_check);
                previous_values.pop_front();
            }
            else {
                // Failed the check
                return to_check;
            }
        }
    }
    std::cerr << "No encoding errors detected. Exiting." << std::endl;
    exit(1);
}

/**
 * Print the sum of the min and max values from the contiguous input range summing up to the encoding error
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::vector<long> input_vector = createInputVector(argv[1]);
    std::pair<long, long> min_max = minMaxFromContiguousRange(input_vector, getFirstInvalidValue(input_vector));

    std::cout << min_max.first + min_max.second << std::endl;
}
