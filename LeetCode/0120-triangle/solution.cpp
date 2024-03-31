class Solution {
    std::vector<std::vector<int>> cache;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        cache = triangle;

        for(int i=cache.size() - 2;i>=0;i--) {
            for(int j=0;j<cache[i].size();j++) {
                cache[i][j] += std::min(cache[i + 1][j], cache[i + 1][j + 1]);
            }
        }

        return cache[0][0];
    }
};
