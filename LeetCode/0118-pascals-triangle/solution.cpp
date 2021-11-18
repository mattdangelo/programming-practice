class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        
        if(numRows == 1) {
            return result;
        }
        
        for(int i=1;i<numRows;i++) {
            std::vector<int> n = {1};
            for(int j=1;j<i;j++) {
                n.push_back(result.at(i-1)[j-1] + result.at(i-1)[j]);
            }
            n.push_back(1);
            result.push_back(n);
        }
        return result;
    }
};
