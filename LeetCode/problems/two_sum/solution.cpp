class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> memo;
        for(int i=0;i<nums.size();i++) {
            memo[nums[i]] = i;
        }
        
        for(int i=0;i<nums.size();i++) {
            int local_target = target - nums[i];
            if(memo.find(local_target) != memo.end()) {
                if(i != memo[local_target]) {
                    vector<int> ret = {i, memo[local_target]};
                    return ret;   
                }
            }
        }
        
        return vector<int>();
    }
};