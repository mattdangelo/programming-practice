class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_max = INT32_MIN;
        int best_max = INT32_MIN;
        
        for(int i : nums) {
            if(current_max == INT32_MIN) {
                current_max = i;
            }
            else {
                current_max += i;
            }
            
            if(current_max > best_max) {
                best_max = current_max;
            }
            
            if(current_max < 0) {
                current_max = 0;
            }
            
        }
        
        return best_max;
    }
};
