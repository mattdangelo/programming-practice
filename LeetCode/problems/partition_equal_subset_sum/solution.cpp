class Solution {
    unordered_map<int, bool> memo;
public:
    bool recPart(vector<int>& nums, int sa, int index, int& total) {
        if(index == nums.size()) {
            return (total - sa) == sa;
        }
            
        int key_a = sa + nums[index];
        if(memo.count(key_a) == 0) {
            memo[key_a] = recPart(nums, sa + nums[index], index + 1, total);
        }

        int key_b = sa; 
        if(memo.count(key_b) == 0) {
            memo[key_b] = recPart(nums, sa, index + 1, total);
        }
        
        return memo[key_a] || memo[key_b];
    }
    
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1) {
            return false;
        }

        int total = 0;
        for(int i : nums) {
            total += i;            
        }

        return recPart(nums, 0, 0, total);
    }
};