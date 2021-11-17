class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            total += (i+1);
        }
        
        return total - sum;
    }
};
