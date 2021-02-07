//
// Created by Matt on 31/01/2021.
//

#include <iostream>
#include <fstream>

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
 * Return the largest seat ID from the specified input file
 * @param filename Input file path
 * @return The highest seat ID
 */
int highestSeatID(char* filename) {
    int current_max = -1;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {
            int id = getSeatID(line);
            if(id > current_max) {
                current_max = id;
            }
        }
    }
    else {
        std::cerr << "Couldn't open file" << std::endl;
        exit(1);
    }
    file.close();
    return current_max;
}

/**
 * Print the highest seat ID
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << highestSeatID(argv[1]) << std::endl;
}
