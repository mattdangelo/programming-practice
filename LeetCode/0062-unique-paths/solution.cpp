class Solution {
public:
    int recUniquePaths(int m, int n, vector<vector<int>>& cache) {
        if(cache[m][n] != -1) {
            return cache[m][n];
        }
   
        // Base case
        if(m == 1 && n == 0 || m == 0 && n == 1) {
            return 1;
        }
        else if(m == 1) {
            cache[m][n - 1] = recUniquePaths(m, n - 1, cache);
            return cache[m][n - 1];
        }
        else if(n == 1) {
            cache[m - 1][n] = recUniquePaths(m - 1, n, cache);
            return cache[m - 1][n];
        }

        // Go down OR right
        cache[m - 1][n] = recUniquePaths(m - 1, n, cache);
        cache[m][n - 1] = recUniquePaths(m, n - 1, cache);
        return cache[m - 1][n] + cache[m][n - 1];
    }

    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> cache(m + 1, std::vector<int> (n + 1, -1));
        int count = recUniquePaths(m, n, cache);
        return count;
    }
};
