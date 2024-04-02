class Solution {
    vector<int> nums;
    vector<int> cache;
public:
    int recRob(int current_idx, int current_cost) {
        // Base case
        if(current_idx >= nums.size()) {
            return current_cost;
        }
        
        if (cache[current_idx] != -1) {
            return cache[current_idx];
        }

        int ans = std::max(recRob(current_idx + 1, current_cost), recRob(current_idx + 2, current_cost) + nums[current_idx]);
        cache[current_idx] = ans;
        return ans;
    }

    int rob(vector<int>& nums) {
        this->nums = nums;
        cache = std::vector<int>(nums.size() + 1, -1);

        return recRob(0, 0);
    }
};
