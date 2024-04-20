class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                // If our point is part of the island...
                if(grid[i][j] == 1) {
                    // Check up
                    if(i <= 0 || grid[i-1][j] == 0) {
                        total++;
                    }
                    // Check down
                    if(i >= (grid.size() - 1) || grid[i+1][j] == 0) {
                        total++;
                    }

                    // Check left
                    if(j <= 0 || grid[i][j - 1] == 0) {
                        total++;
                    }

                    // Check right
                    if(j >= (grid[i].size() - 1) || grid[i][j + 1] == 0) {
                        total++;
                    }
                }
            }
        }

        return total;
    }
};
