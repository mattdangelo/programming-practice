class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int ptr = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0) {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        
        // ptr is number of non-0 elements
        for(int i=ptr;i<nums.size();i++) {
            nums[i] = 0;
        }
    }
};
