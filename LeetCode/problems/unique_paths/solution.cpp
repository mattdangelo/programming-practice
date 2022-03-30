class Solution {
    std::unordered_map<uint64_t, int> memo;
public:
    int uniquePaths(int m, int n) {
        if(m == 1) {
            return 1;
        }
        else if(n == 1) {
            return 1;
        }
        
        uint64_t key_a = min(n - 1, m);
        key_a = key_a << 32;
        key_a = key_a | max(m, n - 1);

        uint64_t key_b = min(n, m - 1);
        key_b = key_b << 32;
        key_b = key_b | max(m - 1, n);
        
        if(memo.find(key_a) == memo.end()) {
            memo[key_a] = uniquePaths(m, n-1);
        }
        
        if(memo.find(key_b) == memo.end()) {
            memo[key_b] = uniquePaths(m - 1, n);
        }
        
        return memo[key_a] + memo[key_b];
    }
};