class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0] = {1};
        for(int i=1;i<numRows;i++) {
            vector<int> row;
            row.reserve(i + 1);
            for(int j=0;j<i+1;j++) {
                int left, right;
                if(j - 1 < 0) {
                    left = 0;
                }
                else {
                    left = res[i - 1][j - 1];
                }

                if(j >= res[i - 1].size()) {
                    right = 0;
                }
                else {
                    right = res[i - 1][j];
                }
                row.push_back(left + right);
            }
            res[i] = row;
        }

        return res;
    }
};