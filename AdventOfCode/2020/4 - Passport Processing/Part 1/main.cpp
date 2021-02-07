//
// Created by Matt on 26/01/2021.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>

/**
 * Return true if a passport string is valid
 * @param passport The passport string
 * @return The validity of the passport string
 */
bool isValid(const std::string& passport) {
    std::string valid_keys[] = {"byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:"};

    std::string buf;
    std::stringstream ss(passport);
    std::set<std::string> tokens;

    while (ss >> buf) {
        tokens.insert(buf.substr(0,4));
    }

    // Check if all the required tokens are present
    if (tokens.size() >= 7) {
        for(const std::string& required : valid_keys) {
            if(tokens.find(required) == tokens.end()) {
                return false;
            }
        }
        return true;
    }
    return false;
}

/**
 * Takes a filename and return the number of valid passports
 * @param filename The name of the file
 * @return The number of valid passports
 */
int numberOfValidPassports(char* filename) {
    int num_of_valid = 0;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string passport, line;
        while(std::getline(file, line)) {
            if(line.length() == 1) {
                // End of the current passport, check if it's valid
                if(isValid(passport)) {
                    num_of_valid++;
                }
                passport = "";
            }
            else {
                // Add this line to the raw passport data
                passport += " " + line;
            }
        }
        if(isValid(passport)) {
            num_of_valid++;
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();

    return num_of_valid;
}

/**
 * Print the total number of valid passports
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << numberOfValidPassports(argv[1]) << std::endl;
}
