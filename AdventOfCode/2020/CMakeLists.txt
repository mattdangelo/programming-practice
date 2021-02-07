cmake_minimum_required(VERSION 3.16)
project(Advent_of_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Advent_of_code_report_repair_part_1 "1 - Report Repair/Part 1/main.cpp"  "1 - Report Repair/Part 1/result.cpp")
add_executable(Advent_of_code_report_repair_part_2 "1 - Report Repair/Part 2/main.cpp"  "1 - Report Repair/Part 2/result.cpp")

add_executable(Advent_of_code_password_philosophy_part_1 "2 - Password Philosophy/Part 1/main.cpp"  "2 - Password Philosophy/Part 1/rule_value.cpp")
add_executable(Advent_of_code_password_philosophy_part_2 "2 - Password Philosophy/Part 2/main.cpp"  "2 - Password Philosophy/Part 2/rule_value.cpp")

add_executable(Advent_of_code_toboggan_trajectory_part_1 "3 - Toboggan Trajectory/Part 1/main.cpp")
add_executable(Advent_of_code_toboggan_trajectory_part_2 "3 - Toboggan Trajectory/Part 2/main.cpp")

add_executable(Advent_of_code_passport_processing_part_1 "4 - Passport Processing/Part 1/main.cpp")
add_executable(Advent_of_code_passport_processing_part_2 "4 - Passport Processing/Part 2/main.cpp")

add_executable(Advent_of_code_binary_boarding_part_1 "5 - Binary Boarding/Part 1/main.cpp")
add_executable(Advent_of_code_binary_boarding_part_2 "5 - Binary Boarding/Part 2/main.cpp")

add_executable(Advent_of_code_custom_customs_part_1  "6 - Custom Customs/Part 1/main.cpp")