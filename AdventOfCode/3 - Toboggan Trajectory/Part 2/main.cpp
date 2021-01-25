//
// Created by Matt on 25/01/2021.
//

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
 * Count the number of trees encountered using a particular right / down configuration
 * @param map The map of trees
 * @param right How many units to travel right each @down
 * @param down The number of rows to travel down each iteration
 * @return The number of trees encountered
 */
long countEncounteredTrees(std::vector<std::vector<bool>>& map, int right, int down) {
    int encountered_trees = 0;

    int row_length = map.at(0).size();
    int column_index = 0;
    for(int i=0;i<map.size();i+=down) {
        std::vector<bool> row = map.at(i);
        if(row.at(column_index)) {
            encountered_trees++;
        }
        column_index = (column_index + right) % (row_length - 1);
    }
    return encountered_trees;
}

/**
 * Return the product of the trees encountered using the strategies outlined in the problem description
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::vector<std::vector<bool>> tree_map = createMap(argv[1]);

    long long result = countEncounteredTrees(tree_map, 1, 1) *
                       countEncounteredTrees(tree_map, 3, 1) *
                       countEncounteredTrees(tree_map, 5, 1) *
                       countEncounteredTrees(tree_map, 7, 1) *
                       countEncounteredTrees(tree_map, 1, 2);

    std::cout << result << std::endl;
}