#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int climbStairs(int n) {
    if(n < 2) {
        return 1;
    }

    if(memo.find(n - 1) == memo.end()) {
        memo[n-1] = climbStairs(n - 1);
    }

    if(memo.find(n - 2) == memo.end()) {
        memo[n-2] = climbStairs(n - 2);
    }

    return memo[n-1] + memo[n-2];
}

int main() {
    std::cout << climbStairs(3) << std::endl;
    return 0;
}
