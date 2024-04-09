class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r * c != mat.size() * mat[0].size()) {
            return mat;
        }
        
        std::vector<std::vector<int>> result;
        std::vector<int> row;
        for(int i=0;i<r * c;i++) {
            row.push_back(mat[i/mat[0].size()][i%mat[0].size()]);
            if(row.size() == c) {
                result.push_back(row);
                row.clear();
            }
        }
        return result;
    }
};