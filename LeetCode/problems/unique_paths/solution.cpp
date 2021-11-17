class Solution {
    std::unordered_map<string, int> memo;
public:
    int uniquePaths(int m, int n) {
        if(m == 1) {
            return 1;
        }
        else if(n == 1) {
            return 1;
        }
        
        string key_a = to_string(min(n - 1, m)) + "_" + to_string(max(m, n - 1));
        string key_b = to_string(min(n, m - 1)) + "_" + to_string(max(m - 1, n));
        
        if(memo.find(key_a) == memo.end()) {
            memo[key_a] = uniquePaths(m, n-1);
        }
        
        if(memo.find(key_b) == memo.end()) {
            memo[key_b] = uniquePaths(m - 1, n);
        }
        
        return memo[key_a] + memo[key_b];
    }
};