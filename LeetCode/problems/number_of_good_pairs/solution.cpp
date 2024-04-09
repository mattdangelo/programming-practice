class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int counts[100] = { 0 };
        int res = 0;
        for(int i : nums) {
            if(counts[i - 1]) {
                res += counts[i - 1];
            }
            counts[i - 1]++;
        }
        return res;
    }
};