class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> result(n + 1, 0);
        for(unsigned int i=1;i<=n;i++) {
            int res = result[i >> 1];
            if(i&1) {
                res++;
            }
            result[i] = res;
        }

        return result;
    }
};