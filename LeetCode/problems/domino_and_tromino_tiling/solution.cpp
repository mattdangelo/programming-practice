class Solution {
    long long memo[1000];
public:
    int numTilings(int n) {
        if(n < 2) {
            return 1;
        }
        else if(n == 2) {
            return 2;
        }
        
        memo[0] = 1;
        memo[1] = 1;
        memo[2] = 2;
        
        if(memo[n - 1] == 0) {
            memo[n - 1] = numTilings(n - 1);
        }
        
        if(memo[n - 3] == 0) {
            memo[n - 3] = numTilings(n - 3);
        }
        
        return (2 * memo[n - 1] + memo[n - 3]) % (int)(pow(10, 9) + 7);
    }
};