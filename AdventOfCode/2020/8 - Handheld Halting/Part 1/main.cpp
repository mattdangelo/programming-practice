//
// Created by Matt on 7/05/2021.
//

#include <iostream>
#include <vector>
#include <fstream>

#include "instruction.h"

/**
 * Create an instruction vector given an input file
 * @param filename The name of the input file
 * @return A vector containing the parsed instructions and their execution count
 */
std::vector<instruction>* generateInstructionsVector(char* filename) {
    auto* instruction_vector = new std::vector<instruction>();

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string instruction = line.substr(0, 3);
            int value = std::stoi(line.substr(3, line.length() - 1));
            instruction_vector->push_back({.executed = false, .instruction = instruction, .value = value});
        }
    }
    return instruction_vector;
}

/**
 * Given a program with an infinite loop, print the value of the accumulator at the moment an instruction is executed
 * twice
 * @param instruction_list The list of instructions given from the generateInstructionsVector method
 * @return The value in the accumulator the moment an instruction is executed twice
 */
int getAccumulatorCount(std::vector<instruction>* instruction_list) {
    int accumulator = 0;
    int instruction_pointer = 0;
    while(true) {
        instruction* i = &instruction_list->at(instruction_pointer);
        std::string instruction = i->instruction;
        int value = i->value;
        bool executed = i->executed;

        if(executed) {
            return accumulator;
        }
        i->executed = true;

        if(instruction == "acc") {
            // Update the accumulator and increment the instruction pointer
            accumulator += value;
            instruction_pointer++;
        }
        else if(instruction == "nop") {
            // Ignore instruction and increment the instruction pointer
            instruction_pointer++;
        }
        else if(instruction == "jmp") {
            // Update the instruction pointer
            instruction_pointer += value;
        }
        else {
            std::cerr << "Invalid program. Terminating execution.";
            exit(1);
        }
    }
}

/**
 * Print the value of the accumulator the moment any instruction is executed twice
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    std::cout << getAccumulatorCount(generateInstructionsVector(argv[1])) << std::endl;
}