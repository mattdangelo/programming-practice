#include <iostream>
#include <vector>

int maxSubArray(std::vector<int>& nums) {
    int max_sum = INT32_MIN;
    int local_sum = INT32_MIN;

    for(int i : nums) {
        if(local_sum < 0) {
            local_sum = 0;
        }

        local_sum += i;

        if(local_sum > max_sum) {
            max_sum = local_sum;
        }
    }

    return max_sum;
}

int main() {
    std::vector<int> input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    std::cout << maxSubArray(input) << std::endl;

    return 0;
}