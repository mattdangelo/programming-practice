//
// Created by Matt on 31/01/2021.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * Get the seat ID from a binary space partitioning string
 * @param bspstring The BSP string (e.g. FBFBBFFRLR)
 * @return The seat ID
 */
int getSeatID(std::string bspstring) {
    int row_lower_bound = 0, char_index = 0;
    int row_upper_bound = 128;
    while(row_lower_bound != row_upper_bound) {
        int avg = (row_upper_bound + row_lower_bound) / 2;
        if(bspstring[char_index] == 'B') {
            row_lower_bound = avg;
        }
        else if(bspstring[char_index] == 'F') {
            row_upper_bound = avg;
        }
        char_index++;
    }

    // At this point, row_lower_bound points to the row

    char_index = 7;
    int col_lower_bound = 0;
    int col_upper_bound = 8;
    while(col_lower_bound != col_upper_bound) {
        int avg = (col_lower_bound + col_upper_bound) / 2;
        if(bspstring[char_index] == 'R') {
            col_lower_bound = avg;
        }
        else if(bspstring[char_index] == 'L') {
            col_upper_bound = avg;
        }
        char_index++;
    }

    // At this point, col_lower_bound points to the col. We can calculate and return the ID.
    return row_lower_bound * 8 + col_lower_bound;
}

/**
 * Return my seat
 * @param filename Input file path
 * @return The ID of my seat
 */
int findMySeat(char* filename) {
    std::vector<int> ids;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            ids.push_back(getSeatID(line));
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();

    // We can sort the list of IDs and look for the first occurrence of an empty seat (assume the block of missing IDs
    // at the front of the plane are contiguous)
    std::sort(ids.begin(), ids.end());
    for(int i=0;i<ids.size()-1;i++) {
        if(ids[i+1] - ids[i] != 1) {
            return ids[i] + 1;
        }
    }
    return -1;
}

/**
 * Print the highest seat ID
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << findMySeat(argv[1]) << std::endl;
}
