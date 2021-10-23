#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++) {
        for(int j=i+1;j<nums.size();j++) {
            if(nums.at(j) == target - nums.at(i)) {
                std::vector<int> indices;
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }

    std::vector<int> error = { INT32_MAX, INT32_MAX };
    return error;
}

int main() {
    std::vector<int> input = { 2, 7, 11, 15 };
    std::vector<int> result = twoSum(input, 9);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}
