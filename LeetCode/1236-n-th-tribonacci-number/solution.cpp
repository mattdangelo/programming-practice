class Solution {
private:
    std::unordered_map<int, int> memo;    
public:
    int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        else if(n == 1 || n == 2) {
            return 1;
        }
        
        if(memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        return memo[n];
    }
};
