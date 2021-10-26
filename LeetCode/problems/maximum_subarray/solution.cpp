class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT32_MIN;
        int local_sum = INT32_MIN;

        for(int i : nums) {
            if(local_sum < 0) {
                local_sum = 0;
            }

            local_sum += i;

            if(local_sum > max_sum) {
                max_sum = local_sum;
            }
        }

        return max_sum;
    }
};