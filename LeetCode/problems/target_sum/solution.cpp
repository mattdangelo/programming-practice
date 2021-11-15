class Solution {
private:
    int count = 0;
    std::unordered_map<std::string, int> memo;
public:
    int recFindTargetSumWays(vector<int> nums, int target, int index) {
        if(index == nums.size()) {
            if(target == 0) {
                return 1;
            }
            return 0;
        }
        
        std::string key_a = std::to_string(target + nums[index]) + "_" + std::to_string(index + 1);
        if(memo.find(key_a) == memo.end()) {
            memo[key_a] = recFindTargetSumWays(nums, target + nums[index], index + 1);
        }
        
        std::string key_b = std::to_string(target - nums[index]) + "_" + std::to_string(index + 1);
        if(memo.find(key_b) == memo.end()) {
            memo[key_b] = recFindTargetSumWays(nums, target - nums[index], index + 1);
        }

        return memo[key_a] + memo[key_b];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return recFindTargetSumWays(nums, target, 0);
    }
};