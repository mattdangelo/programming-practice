//
// Created by Matt on 7/05/2021.
//

#include <iostream>
#include <vector>
#include <fstream>

#include "instruction.h"
#include "result.h"

/**
 * Create an instruction vector given an input file
 * @param filename The name of the input file
 * @return A vector containing the parsed instructions and their execution count indexes set to 0
 */
std::vector<instruction>* generateInstructionsVector(char* filename) {
    auto* instruction_vector = new std::vector<instruction>();

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string instruction = line.substr(0, 3);
            int value = std::stoi(line.substr(3, line.length() - 1));
            instruction_vector->push_back({.executed_at_index = 0, .instruction = instruction, .value = value});
        }
    }
    return instruction_vector;
}

/**
 * Execute a list of instructions and check for re-execution at a given execution count index
 * @param instruction_list The list of instructions to execute
 * @param execution_count_index A unique index for this execution
 * @return A result indicating if a loop was detected or we exited gracefully
 */
result execute(std::vector<instruction>* instruction_list, unsigned int execution_count_index) {
    int accumulator = 0;
    int instruction_pointer = 0;
    while(true) {
        instruction* i = &instruction_list->at(instruction_pointer);
        std::string instruction = i->instruction;
        int value = i->value;
        unsigned int executed_index = i->executed_at_index;

        // Check if we last executed this instruction at our current index
        if(executed_index == execution_count_index) {
            // Loop detected
            return result {.finished_execution = false, .accumulator_value = accumulator};
        }
        i->executed_at_index = execution_count_index;

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

        // Check if we have finished execution
        if(instruction_pointer == instruction_list->size()) {
            return result {.finished_execution = true, .accumulator_value = accumulator};
        }
    }
}

/**
 * Given a program with an infinite loop, correct the program, and return the value of the accumulator when the program
 * completes
 * @param instruction_list The list of instructions given from the generateInstructionsVector method
 * @return The value in the accumulator the moment the program completes execution
 */
int getAccumulatorCount(std::vector<instruction>* instruction_list) {
    for(int i = 0; i < instruction_list->size(); i++) {
        result r;
        std::string instruction = instruction_list->at(i).instruction;
        if(instruction == "nop") {
            // Try converting it to a jmp, run it and check result
            instruction_list->at(i).instruction = "jmp";
            r = execute(instruction_list, i + 1);
            if(r.finished_execution) {
                return r.accumulator_value;
            }
            else {
                // We failed, put it back to a nop
                instruction_list->at(i).instruction = "nop";
            }
        }
        else if(instruction == "jmp") {
            // Try converting it to a nop, run it and check result
            instruction_list->at(i).instruction = "nop";
            r = execute(instruction_list, i + 1);
            if(r.finished_execution) {
                return r.accumulator_value;
            }
            else {
                // We failed, put it back to a jmp
                instruction_list->at(i).instruction = "jmp";
            }
        }
    }
    std::cerr << "Program could not be corrected. Terminating execution.";
    exit(1);
}

/**
 * Print the value of the accumulator the moment any instruction is executed twice
 */
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: main [file path]" << std::endl;
        return 1;
    }

    auto instruction_list = generateInstructionsVector(argv[1]);

    std::cout << getAccumulatorCount(instruction_list) << std::endl;
}