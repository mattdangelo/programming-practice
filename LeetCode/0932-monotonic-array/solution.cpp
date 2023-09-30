class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // Trivial
        if(nums.size() == 1) {
            return true;
        }

        bool increasing = true;
        bool decreasing = true;

        for(int i=1;i<nums.size();i++) {
            if(nums[i - 1] > nums[i]) {
                increasing = false;
            }
            else if(nums[i - 1] < nums[i]) {
                decreasing = false;
            }

            if(!increasing && !decreasing) {
                return false;
            }
        }

        return true;
    }
};
