class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret;
        if(numRows == 0) {
            return ret;
        }
        
        ret.reserve(numRows);
        
        ret.push_back({1});
        
        for(int i=1;i<numRows;i++) {
            int rowCount = i + 1;
            std::vector<int> row;
            row.reserve(rowCount);
            for(int j=0;j<rowCount;j++) {
                //int prevRow = i - 1;
                int prevLeft = (j - 1) < 0 ? 0 : ret[i-1][j-1];
                int prevRight = j >= ret[i-1].size() ? 0 : ret[i-1][j];
                row.push_back(prevLeft + prevRight);
            }
            ret.push_back(row);
        }
        
        return ret;
    }
};