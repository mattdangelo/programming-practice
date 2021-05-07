cmake_minimum_required(VERSION 3.16)
project(Advent_of_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(Advent_of_code_report_repair_part_1 "1 - Report Repair/Part 1/main.cpp")
add_executable(Advent_of_code_report_repair_part_2 "1 - Report Repair/Part 2/main.cpp")

add_executable(Advent_of_code_password_philosophy_part_1 "2 - Password Philosophy/Part 1/main.cpp"  "2 - Password Philosophy/Part 1/rule_value.cpp")
add_executable(Advent_of_code_password_philosophy_part_2 "2 - Password Philosophy/Part 2/main.cpp"  "2 - Password Philosophy/Part 2/rule_value.cpp")

add_executable(Advent_of_code_toboggan_trajectory_part_1 "3 - Toboggan Trajectory/Part 1/main.cpp")
add_executable(Advent_of_code_toboggan_trajectory_part_2 "3 - Toboggan Trajectory/Part 2/main.cpp")

add_executable(Advent_of_code_passport_processing_part_1 "4 - Passport Processing/Part 1/main.cpp")
add_executable(Advent_of_code_passport_processing_part_2 "4 - Passport Processing/Part 2/main.cpp")

add_executable(Advent_of_code_binary_boarding_part_1 "5 - Binary Boarding/Part 1/main.cpp")
add_executable(Advent_of_code_binary_boarding_part_2 "5 - Binary Boarding/Part 2/main.cpp")

add_executable(Advent_of_code_custom_customs_part_1  "6 - Custom Customs/Part 1/main.cpp" "Shared/utils.cpp")
add_executable(Advent_of_code_custom_customs_part_2  "6 - Custom Customs/Part 2/main.cpp" "Shared/utils.cpp")

add_executable(Advent_of_code_handy_haversacks_part_1  "7 - Handy Haversacks/Part 1/main.cpp" "Shared/utils.cpp")

add_executable(Advent_of_code_handheld_halting_part_1  "8 - Handheld Halting/Part 1/main.cpp")
add_executable(Advent_of_code_handheld_halting_part_2  "8 - Handheld Halting/Part 2/main.cpp")

add_executable(Advent_of_code_encoding_error_part_1  "9 - Encoding Error/Part 1/main.cpp")