class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> count;
        int best = 0;
        int sum = 0;
        
        for(int i=0;i<nums.size();i++) {
            sum += nums[i] == 0 ? -1 : 1;
            
            auto it = count.find(sum);
            
            if(sum == 0) {
                best = i + 1;
            }
            else if(it == count.end()) {
                count.insert({sum, i});
            }
            else if(it != count.end()) {
                best = std::max(best, i - it->second);
            }
        }
        
        return best;
    }
};