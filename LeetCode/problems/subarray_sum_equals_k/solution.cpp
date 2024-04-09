class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        
        int res = 0;
        int cur_sum = 0;
        
        for(int i : nums) {
            cur_sum += i;
            int diff = cur_sum - k;
            if(prefix_sum.count(diff)) {
                res += prefix_sum[diff];
            }
             
            if(prefix_sum.count(cur_sum)) {
                prefix_sum[cur_sum]++;
            }
            else {
                prefix_sum[cur_sum] = 1;
            }
        }
        
        return res;
    }
};