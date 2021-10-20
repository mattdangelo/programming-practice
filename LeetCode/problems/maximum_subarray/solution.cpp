class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int local_sum = nums[0];

        for (int right = 1; right < nums.size(); right++) {
            if (local_sum < 0) {
                local_sum = 0;
            }

            local_sum += nums[right];

            max_sum = local_sum > max_sum ? local_sum : max_sum;
        }

        return max_sum;
    }
};