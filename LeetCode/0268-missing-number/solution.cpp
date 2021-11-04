class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int actual = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            actual += (i + 1);
        }

        return actual - sum;
    }
};
