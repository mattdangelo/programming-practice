class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> values;
        
        // O(n) insertion into set
        for(int i : nums) {
            values.insert(i);
        }
        
        int best = 0;
        for(int i : nums) {
            if(values.count(i - 1) == 0) {
                int local_best = 1;
                int j = i + 1;
                while(values.count(j)) {
                    j++;
                    local_best++;
                } 
                best = std::max(best, local_best);
            }
        }
        
        return best;
    }
};