class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> cpy(nums.size());
        
        for(int i=0;i<nums.size();i++) {
            cpy[i] = nums[i];
        }

        for(int i=0;i<nums.size();i++) {
            nums[(i + k) % nums.size()] = cpy[i];
        }
    }
};