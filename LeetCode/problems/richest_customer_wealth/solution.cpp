class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        for(int i=0;i<accounts.size();i++) {
            int local_max = 0;
            for(int j : accounts[i]) {
                local_max += j;
            }
            max = std::max(local_max, max);
        }
        
        return max;
    }
};