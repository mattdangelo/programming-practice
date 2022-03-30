class Solution {
private:
    std::unordered_map<int, int> memo;    
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }

        if (memo.count(n - 1) == 0) {
            memo[n - 1] = fib(n - 1);
        }

        if (memo.count(n - 2) == 0) {
            memo[n - 2] = fib(n - 2);
        }

        return memo[n - 1] + memo[n - 2];
    }
};