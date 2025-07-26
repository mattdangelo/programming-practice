class Solution {
public:
    int maxSum(vector<int>& nums) {
        int max = *std::max_element(nums.begin(), nums.end());

        // If the max value in the list is < 0, the result is that value
        if(max < 0) {
            return max;
        }

        // Otherwise, it's the sum of the unique positive values in the list
        int res = 0;
        std::unordered_set<int> seen;
        for(int i : nums) {
            if(!seen.contains(i) && i > 0) {
                seen.insert(i);
                res += i;
            }
        }

        return res;
    }
};
