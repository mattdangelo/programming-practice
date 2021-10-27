#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, std::vector<int>> val_to_indexes;

    for(int i=0;i<nums.size();i++) {
        if(val_to_indexes.count(nums[i])) {
            val_to_indexes[nums[i]].push_back(i);
        }
        else {
            val_to_indexes[nums[i]] = { i };
        }
    }

    for(int i=0;i<nums.size();i++) {
        int to_find = target - nums[i];

        if(val_to_indexes.count(to_find)) {
            std::vector<int> index_info = val_to_indexes[to_find];

            if(to_find == nums[i]) {
                if(index_info.size() > 1) {
                    // Make sure we don't return the same index for both indexes
                    return { index_info[0], index_info[1] };
                }
            }
            else {
                return { i , index_info[0] };
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
