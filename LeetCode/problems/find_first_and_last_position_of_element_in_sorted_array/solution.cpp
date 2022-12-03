class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> ret = {-1, -1};
        
        if(nums.size() == 0) {
            return ret;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // First pass - binary search for first instance of the target
        while(right - left > 1) {
            mid = (right + left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        
        // Early return if there were no instances of the target value found
        if(nums[left] == target) {
            ret[0] = left;   
        }
        else if(nums[right] == target) {
            ret[0] = right;
        }
        else {
            return ret;
        }

        left = 0;
        right = nums.size() - 1;

        // Second pass - binary search for last instance of the target
        while(right - left > 1) {
            mid = (right + left) / 2;
            if(nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        if(nums[right] == target) {
            ret[1] = right;
        }
        else if(nums[left] == target) {
            ret[1] = left;   
        }

        return ret;
    }
};