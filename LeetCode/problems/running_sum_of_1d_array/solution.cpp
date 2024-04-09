class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> result(nums.size());
        
        int current = 0;
        for(int i=0;i<nums.size();i++) {
            current += nums[i];
            result[i] = current;
        }
        
        return result;
    }
};