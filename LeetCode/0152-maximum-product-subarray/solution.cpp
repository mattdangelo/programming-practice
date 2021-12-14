class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums[0];
        int local_min = nums[0];
        int local_max = nums[0];
        int i = 1;
        
        while(i < nums.size()) {
            if(nums[i] == 0) {
                // reset our min / max
                best = max(best, 0);
                local_max = 1;
                local_min = 1;
                i++;
                continue;
            }
            
            int temp = local_max * nums[i];
            local_max = max(nums[i], max(local_max * nums[i], local_min * nums[i]));
            local_min = min(nums[i], min(local_min * nums[i], temp));
                                        
            best = max(best, local_max);
            
            i++;
        }
        
        return best;
    }
};
