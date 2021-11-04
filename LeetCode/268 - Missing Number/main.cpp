#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int sum = 0;
    int actual = 0;
    for(int i=0;i<nums.size();i++) {
        sum += nums[i];
        actual += (i + 1);
    }

    return actual - sum;
}

int main() {
    std::vector<int> input = { 3, 0, 1 };
    std::cout << missingNumber(input) << std::endl;

    return 0;
}