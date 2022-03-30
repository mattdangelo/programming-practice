class Solution {
    std::unordered_map<uint64_t, int> memo;
public:
    int recFindTargetSumWays(vector<int>& nums, int target, int index) {
        if(index >= nums.size()) {
            return target == 0;
        }
        
        uint64_t key_a = target + nums[index];
        key_a = key_a << 32;
        key_a = key_a | index + 1;
        if(memo.count(key_a) == 0) {
            memo[key_a] = recFindTargetSumWays(nums, target + nums[index], index + 1);
        }
        
        uint64_t key_b = target - nums[index];
        key_b = key_b << 32;
        key_b = key_b | index + 1;
        if(memo.count(key_b) == 0) {
            memo[key_b] = recFindTargetSumWays(nums, target - nums[index], index + 1);
        }
        
        return memo[key_a] + memo[key_b];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return recFindTargetSumWays(nums, target, 0);
    }
};