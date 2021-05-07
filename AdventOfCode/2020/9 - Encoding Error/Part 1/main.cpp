//
// Created by Matt on 7/05/2021.
//

#include <iostream>
#include <fstream>
#include <deque>
#include <set>

/**
 * Print the first value in the sequence which does not adhere to the sum rule
 * @param filename The name of the file with the values to check
 * @return The first element that does not adhere to the sum rule
 */
unsigned long getFirstInvalidValue(char* filename) {
    std::ifstream file(filename);
    int index = 0;
    std::deque<long> previous_values;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if(index < 25) {
                previous_values.push_back(stol(line));
            }
            else {
                long to_check = stol(line);
                std::set<long> previous_25_set = std::set<long>(previous_values.begin(), previous_values.end());
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
            index++;
        }
    }
    std::cerr << "No encoding errors detected. Exiting." << std::endl;
    exit(1);
}

/**
 * Print the first value in the sequence which does not adhere to the sum rule
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << getFirstInvalidValue(argv[1]) << std::endl;
}