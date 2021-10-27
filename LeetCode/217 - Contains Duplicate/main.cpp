#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int i : nums) {
        if (seen.find(i) != seen.end()) {
            return true;
        }
        else {
            seen.insert(i);
        }
    }

    return false;
}

int main() {
    std::vector<int> input = { 1, 2, 3, 1 };
    std::cout << containsDuplicate(input) << std::endl;
    return 0;
}