#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> val_to_index;

    for(int i=0;i<nums.size();i++) {
        int to_find = target - nums[i];

        if(val_to_index.count(to_find)) {
            return { val_to_index[to_find], i };
        }
        else {
            val_to_index[nums[i]] = i ;
        }
    }

    std::vector<int> error = { INT32_MAX, INT32_MAX };
    return error;
}

int main() {
    std::vector<int> input = { 3,3 };
    std::vector<int> result = twoSum(input, 6);
    std::cout << result[0] << " " << result[1] << std::endl;
    return 0;
}
