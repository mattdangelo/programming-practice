class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        std::vector<std::vector<int>> ret;

        int required_elements = m * n;
        if(required_elements != original.size()) {
            return ret;
        }

        ret.reserve(m);

        int ptr = 0;
        for(int i=0;i<m;i++) {
            std::vector<int> row(n);
            for(int j=0;j<n;j++) {
                row[j] = original[ptr];
                ptr++;
            }
            ret.push_back(row);
        }

        return ret;
    }
};
