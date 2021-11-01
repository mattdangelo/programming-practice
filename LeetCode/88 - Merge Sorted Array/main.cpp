#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    if(n == 0) {
        return;
    }
    else {
        for(int i=0;i<nums2.size();i++) {
            nums1[m + i] = nums2[i];
        }
    }

    std::sort(nums1.begin(), nums1.end());
}

int main() {
    std::vector<int> input_1 = {1,2,3,0,0,0};
    std::vector<int> input_2 = {2,5,6};

    merge(input_1, 3, input_2, 3);

    for(int i : input_1) {
        std::cout << i << " " << std::endl;
    }

    return 0;
}