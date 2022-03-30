class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowmin;
        int rowmax;
        int index = 0;
        
        for(int i=0;i<matrix.size();i++) {
            rowmin = matrix[i][0];
            rowmax = matrix[i][matrix[i].size() - 1];
            
            if((rowmin < target && rowmax > target) || rowmin == target || rowmax == target) {
                break;
            }
            else {
                index++;
            }
        }
        
        if(index >= matrix.size()) {
            return false;
        }
        else {
            int l = 0;
            int r = matrix[index].size();

            while (l <= r) {
                int m = l + (r - l) / 2;

                if (matrix[index][m] == target) {
                    return true;
                }

                if (matrix[index][m] < target) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }

            return false;
        }
    }
};