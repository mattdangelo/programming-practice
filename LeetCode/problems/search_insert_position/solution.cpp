class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        int midpoint = 0;
        while(left <= right) {
            midpoint = left + (right - left) / 2;
            if(nums[midpoint] == target) {
                return midpoint;
            }
            else if(nums[midpoint] < target) {
                left = midpoint + 1;
            }
            else {
                right = midpoint - 1;
            }
        }
        
        return nums[midpoint] < target ? midpoint + 1 : midpoint;
    }
};