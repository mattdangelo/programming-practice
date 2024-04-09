class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int remainders[60] = {0};
        int count = 0;
        for(int i : time) {
            if(i%60 == 0) {
                count += remainders[0];
            }
            else {
                count += remainders[60 - (i % 60)];
            }
            remainders[i % 60]++;
        }
        
        return count;
    }
};