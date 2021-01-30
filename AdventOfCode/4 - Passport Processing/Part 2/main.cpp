//
// Created by Matt on 26/01/2021.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <functional>

std::map<std::string, std::function<bool(std::string)>> validations;

/**
 * Returns true if string value is between min and max inclusive
 * @param value The value to test
 * @param min The min value
 * @param max The max value
 * @return true if min <= value <= max, false otherwise
 */
bool isBetween(const std::string& value, int min, int max) {
    int converted_value = std::atoi(value.c_str());
    return converted_value >= min && converted_value <= max;
}

/**
 * Populate the validation map
 */
void populateValidations() {
    validations.emplace("byr:", [](const std::string& val) { return isBetween(val, 1920, 2002); });
    validations.emplace("iyr:", [](const std::string& val) { return isBetween(val, 2010, 2020); });
    validations.emplace("eyr:", [](const std::string& val) { return isBetween(val, 2020, 2030); });
    validations.emplace("hgt:", [](const std::string& val) {
                            std::string unit = val.substr(val.length() - 2, val.length());
                            std::string value = val.substr(0, val.length() - 2);
                            if(unit == "cm") {
                                return isBetween(value, 150, 193);
                            }
                            else if(unit == "in") {
                                return isBetween(value, 59, 76);
                            }
                            else {
                                return false;
                            }
                        });
    validations.emplace("hcl:", [](const std::string& val) {
                            if(val[0] != '#' || val.length() != 7) {
                                return false;
                            }

                            std::set<char> valid_letters = {'a', 'b', 'c', 'd', 'e', 'f'};
                            for(int i=1;i<7;i++) {
                                if(!isdigit(val[i]) && valid_letters.find(val[i]) == valid_letters.end()) {
                                    return false;
                                }
                            }
                            return true;
                        });
    validations.emplace("ecl:", [](const std::string& val) {
                            std::set<std::string> valid_eye_colours = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
                            return valid_eye_colours.find(val) != valid_eye_colours.end();
    });
    validations.emplace("pid:", [](const std::string& val) {
                            if(val.length() != 9) {
                                return false;
                            }

                            for(char c : val) {
                                if(!isdigit(c)) {
                                    return false;
                                }
                            }
                            return true;
                        });
}

/**
 * Return true if a passport string is valid
 * @param passport The passport string
 * @return The validity of the passport string
 */
bool isValid(const std::string& passport) {
    std::string buf;
    std::stringstream ss(passport);
    std::map<std::string, std::string> key_values;

    while (ss >> buf) {
        key_values.emplace(buf.substr(0,4), buf.substr(4,buf.length()));
    }

    // Check if all the required tokens are present
    if (key_values.size() >= 7) {
        for(auto & validation : validations) {
            std::string required = validation.first;
            if(key_values.count(required) > 0) {
                std::function<bool(std::string)> validation_func = validation.second;
                if(!validation_func(key_values[required])) {
                    return false;
                }
            }
            else {
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
 * Return the total number of valid passports
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    populateValidations();

    std::cout << numberOfValidPassports(argv[1]) << std::endl;
}
