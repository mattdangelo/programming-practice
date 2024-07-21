class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        std::unordered_set<int> min_rows;

        for(int i=0;i<matrix.size();i++) {
            min_rows.insert(*min_element(matrix[i].begin(), matrix[i].end()));
        }

        std::vector<int> res;

        for(int i=0;i<matrix[0].size();i++) {
            int max = INT_MIN;
            for(int j=0;j<matrix.size();j++) {
                max = std::max(max, matrix[j][i]);
            }
   
            if(min_rows.contains(max)) {
                res.push_back(max);
            }
        }

        return res;
    }
};
