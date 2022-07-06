class Solution {
    std::unordered_map<int, int> cache;
public:
    int fib(int n) {
        if(n < 2) {
            return n;
        }
        
        if(cache.count(n - 1) == 0) {
            cache[n - 1] = fib(n - 1);
        }
        
        if(cache.count(n - 2) == 0) {
            cache[n - 2] = fib(n - 2);
        }
        
        return cache[n - 1] + cache[n - 2];
    }
};
