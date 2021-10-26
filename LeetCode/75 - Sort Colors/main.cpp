#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) {
    for(int i=0;i<nums.size();i++) {
        for(int j=0;j<nums.size();j++) {
            if(nums[i] < nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int main() {
    std::vector<int> input = {2,0,2,1,1,0};

    sortColors(input);

    for(int i : input) {
        std::cout << i << " " << std::endl;
    }

    return 0;
}