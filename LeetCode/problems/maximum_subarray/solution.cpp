class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = INT32_MIN;
        
        int total = 0;
        for(int i : nums) {
            total += i;
            best = max(total, best);
            if(total < 0) {
                total = 0;
            }
        }
        
        return best;
    }
};