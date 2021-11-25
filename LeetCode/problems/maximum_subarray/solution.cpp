class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT32_MIN;
        
        int ptr = 0;
        int local_best = 0;
        
        while(ptr < nums.size()) {
            local_best += nums[ptr];

            if(local_best > best) {
                best = local_best;
            }

            if(local_best < 0) {
                local_best = 0;
            }
            
            ptr++;
        }
        
        return best;
    }
};