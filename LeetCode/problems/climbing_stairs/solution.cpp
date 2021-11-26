class Solution {
    unordered_map<int, int> memo;
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        
        if(memo.count(n - 1) == 0) {
            memo[n - 1] = climbStairs(n - 1);
        }

        if(memo.count(n - 2) == 0) {
            memo[n - 2] = climbStairs(n - 2);
        }
        
        return memo[n - 1] + memo[n - 2];
    }
};