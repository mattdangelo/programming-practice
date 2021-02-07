//
// Created by Matt on 7/02/2021.
//

#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <map>

#include "../../Shared/utils.h"

/**
 * Calculate the number of bags that eventually lead to the target bag type
 * @param map The bag map
 * @param target The target bag type
 * @return The number of bags that can directly or indirectly contain the target bag type
 */
int getBagCount(std::map<std::string, std::set<std::string>>* map, const std::string& target) {
    int prev_count;
    std::set<std::string> lead_to_target;

    // Iterate until the number of bags in the count does not change
    do {
        prev_count = lead_to_target.size();
        std::map<std::string, std::set<std::string>>::iterator it;
        for (it = map->begin(); it != map->end(); it++) {
            for(const std::string& s : it->second) {
                if(lead_to_target.count(s) > 0 || s == target) {
                    lead_to_target.insert(it->first);
                }
            }
        }
    }
    while(lead_to_target.size() != prev_count);

    return prev_count;
}

/**
 * Create a map of bags and their containing bags
 * @param filename The name of the rules for how bags are related
 * @return A pointer to the mapping of bags
 */
std::map<std::string, std::set<std::string>>* createBagMap(char* filename) {
    auto bag_map = new std::map<std::string, std::set<std::string>>();
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::vector<std::string> redundant{"bag", "bags"};
        while(std::getline(file, line)) {
            std::istringstream ss = std::istringstream(line);
            std::string word, buffer, name;
            std::set<std::string> contains;
            while (ss >> word) {
                word = utils::stripFormatting(word);
                if(word == "contain") {
                    name = utils::removeFromString(buffer.substr(1, buffer.size()), redundant);
                    name = name.substr(0, name.length() - 1);
                    buffer = "";
                }
                else if(isdigit(word[0])) {
                    if(!buffer.empty()) {
                        std::string to_add = utils::removeFromString(buffer.substr(1, buffer.size()), redundant);
                        contains.insert(to_add.substr(0, to_add.length() - 1));
                        buffer = "";
                    }
                }
                else {
                    buffer += " " + word;
                }
            }
            std::string to_add = utils::removeFromString(buffer.substr(1, buffer.size()), redundant);
            contains.insert(to_add.substr(0, to_add.length() - 1));

            bag_map->emplace(name, contains);
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();
    return bag_map;
}

/**
 * Print the number of bags that eventually lead to a shiny gold bag
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << getBagCount(createBagMap(argv[1]), "shiny gold") << std::endl;
}