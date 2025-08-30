class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        std::vector<int> diag;
        diag.reserve(n);

        // Starting on main diagonal and going bottom left
        for (int row=0; row<n;row++) {
            int i=row; 
            int j=0;

            // First pass: populate diag
            while (i<n && j<n) {
                diag.push_back(grid[i][j]);
                i++; 
                j++;
            }

            std::sort(diag.begin(), diag.end());
            i=row; 
            j=0;

            // Second pass: re-populate matrix
            while (i<n && j<n) {
                grid[i][j] = diag.back();
                diag.pop_back();
                i++; 
                j++;
            }
        }

        // Starting on main diagonal and going top right
        for (int col=1;col<n;col++) {
            int i=0; 
            int j=col;

            // First pass: populate diag
            while (i<n && j<n) {
                diag.push_back(grid[i][j]);
                i++; 
                j++;
            }

            std::sort(diag.begin(), diag.end(), std::greater<>());
            i=0; 
            j=col;

            // Second pass: re-populate matrix
            while (i<n && j<n) {
                grid[i][j] = diag.back();
                diag.pop_back();
                i++; 
                j++;
            }

        }

        return grid;
    }
};
