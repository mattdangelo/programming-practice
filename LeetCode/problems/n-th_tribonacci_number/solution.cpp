class Solution {
    std::unordered_map<int, int> memo;
public:
    Solution() {
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
    }

    int tribonacci(int n) {
        if(memo.count(n) != 0) {
            return memo[n];
        }
        else {
            int res = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
            memo[n] = res;
            return res;
        }
    }
};