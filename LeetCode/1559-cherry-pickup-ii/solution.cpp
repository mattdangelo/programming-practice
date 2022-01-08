class Solution {
public:
    int dp[70][70][70] = {};
    int rows;
    int cols;

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        rows = grid.size();
        cols = grid[0].size();
        return dfs(grid, 0, 0, grid[0].size()-1);
    }
    
    int dfs(vector<vector<int>>& grid, int r, int c1, int c2) {
        if(r == rows) {
            return 0;
        }
        
        if(dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        
        int ans = 0;
        for(int i=-1; i<=1;i++) {
            for(int j=-1;j<=1;j++) {
                int nc1 = c1 + i;
                int nc2 = c2 + j;
                if(nc1 >= 0 && nc1 < cols && nc2 >= 0 && nc2 < cols) {
                    ans = max(ans, dfs(grid, r+1, nc1, nc2));
                }
            }
        }
        
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        dp[r][c1][c2] = ans + cherries;
        return dp[r][c1][c2];
    }
};
