#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> memo;

int rob(std::vector<int>& nums, int index) {
    if (index >= nums.size()) {
        return 0;
    }

    if (memo.count(index + 1) == 0) {
        memo[index + 1] = rob(nums, index + 1);
    }

    if (memo.count(index + 2) == 0) {
        memo[index + 2] = rob(nums, index + 2);
    }

    return std::max(memo[index + 1], memo[index + 2] + nums[index]);
}

int rob(std::vector<int>& nums) {
    return rob(nums, 0);
}

int main() {
    std::vector<int> input = { 1, 2, 3, 1 };
    std::cout << rob(input) << std::endl;
    return 0;
}