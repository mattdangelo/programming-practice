#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> results;

    if(nums.size() < 3) {
        return results;
    }

    std::sort(nums.begin(), nums.end());

    for(int i=0;i<nums.size();i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int diff = nums[i] + nums[right] + nums[left];
            if (diff < 0) {
                left++;
            }
            else if (diff > 0) {
                right--;
            }
            else {
                results.push_back(std::vector<int> { nums[i], nums[left], nums[right] });
                left++;
                while(nums[left] == nums[left - 1] && left < right) {
                    left++;
                }
            }
        }
    }

    return results;
}

int main() {
    std::vector<int> input = {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = threeSum(input);

    for(const std::vector<int>& answer : result) {
        for(int i : answer) {
            std::cout << i << " " << std::endl;
        }
        std::cout << std::endl;
    }
}