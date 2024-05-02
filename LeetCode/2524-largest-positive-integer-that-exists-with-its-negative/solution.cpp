class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Sort nums
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        // 2 pointer approach
        while(left < right) {
            if(nums[left] < -nums[right]) {
                left++;
            }
            else if(nums[left] > -nums[right]) {
                right--;
            }
            else {
                return nums[right];
            }
        }

        return -1;
    }
};
