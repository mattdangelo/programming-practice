class Solution {
    int n;
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        n = grid.size();
        std::vector<std::vector<int>> ret(n - 2);

        for(int i=1;i<grid.size() - 1;i++) {
            std::vector<int> row(n - 2);

            for(int j=1;j<grid.size() - 1;j++) {
                // Check the 3x3 grid around i, j
                int best = grid[i - 1][j - 1];

                best = std::max(best, std::max(grid[i][j - 1], grid[i + 1][j - 1]));
                best = std::max(best, std::max(grid[i - 1][j], std::max(grid[i + 1][j], grid[i][j])));
                best = std::max(best, std::max(grid[i - 1][j + 1], std::max(grid[i + 1][j + 1], grid[i][j + 1])));

                row[j - 1] = best;
            }
            ret[i - 1] = row;
        }

        return ret;
    }
};
