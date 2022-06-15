class Solution {
public:
    int recMinTotal(std::vector<std::vector<int>>& t, std::vector<std::vector<int>>& c, int level, int index, int max_level, int current_total) {
        if(level == max_level) {
            return current_total;
        }
        
        if(c[level][index] != INT_MAX) {
                return c[level][index];
        }

        int a = recMinTotal(t, c, level + 1, index, max_level, current_total) + t[level][index];
        int b =  recMinTotal(t, c, level + 1, index + 1, max_level, current_total) + t[level][index];
        c[level][index] = std::min(a, b);
        return c[level][index];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        std::vector<std::vector<int>> cache(triangle.size(), vector<int>(triangle.size(), INT_MAX));
        return recMinTotal(triangle, cache, 0, 0, triangle.size(), 0);
    }
};
