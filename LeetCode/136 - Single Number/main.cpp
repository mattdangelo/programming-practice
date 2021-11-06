#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int result = 0;
    for(int i : nums) {
        result ^= i;
    }

    return result;
}

int main() {
    std::vector<int> input = { 2, 2, 1 };
    std::cout << singleNumber(input) << std::endl;

    return 0;
}