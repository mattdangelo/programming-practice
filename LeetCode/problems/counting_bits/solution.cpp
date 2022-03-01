class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res(n + 1);
        
        res[0] = 0;
        for(int i=1;i<n+1;i++) {
            if((i & (i - 1)) == 0) {
                res[i] = 1;
            }
            else {
                res[i] = res[i/2] + i%2;
            }
        }
        
        return res;
    }
};