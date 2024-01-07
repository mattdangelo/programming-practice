class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int best = 1;
        std::vector<int> cache(nums.size());
        for(int i=0;i<nums.size();i++) {
            cache[i] = 1;
        }

        for(int i=nums.size()-1;i>=0;i--) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[i] < nums[j]) {
                    cache[i] = std::max(cache[i], 1 + cache[j]);
                    best = std::max(best, cache[i]);
                }
            }
        }

        return best;
    }
};
