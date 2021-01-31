//
// Created by Matt on 25/01/2021.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

/**
 * Takes a filename and creates a 2D tree map
 * @param filename The name of the file
 * @return The tree map, where map[i][j] indicates if a tree is present
 */
std::vector<std::vector<bool>> createMap(char* filename) {
    std::vector<std::vector<bool>> map;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            std::vector<bool> row;
            for(char c : line) {
                row.push_back(c == '#');
            }
            map.push_back(row);
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();
    return map;
}

/**
 * Return the total number of encountered trees
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::vector<std::vector<bool>> tree_map = createMap(argv[1]);
    int encountered_trees = 0;

    int row_length = tree_map.at(0).size();
    int column_index = 0;
    for(std::vector<bool> row : tree_map) {
        if(row.at(column_index)) {
            encountered_trees++;
        }
        column_index = (column_index + 3) % (row_length - 1);
    }

    std::cout << encountered_trees << std::endl;
}
