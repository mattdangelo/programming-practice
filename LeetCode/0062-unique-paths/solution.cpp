class Solution {
    int memo[101][101];
public:
    int recUniquePaths(int m, int n) {
        if((m <= 1) || (n <= 1)) {
            return 1;
        }
        
        if(memo[n - 1][m] == -1) {
            memo[n - 1][m] = recUniquePaths(n - 1, m);
        }
        
        if(memo[n][m - 1] == -1) {
            memo[n][m - 1] = recUniquePaths(n, m - 1);
        }
        
        return memo[n - 1][m] + memo[n][m - 1];
    }

    int uniquePaths(int m, int n) {
        for(int i=0;i<101;i++) {
            for (int j=0;j<101;j++) {
                memo[i][j] = -1;
            }
        }
        
        return recUniquePaths(m, n);
    }
};
