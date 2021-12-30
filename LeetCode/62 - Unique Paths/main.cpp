#include <iostream>
#include <unordered_map>

std::unordered_map<uint64_t, int> memo;

int uniquePaths(int m, int n) {
    if (m == 1) {
        return 1;
    }
    else if (n == 1) {
        return 1;
    }

    uint64_t key_a = std::min(n - 1, m);
    key_a = key_a << 32;
    key_a = key_a | std::max(m, n - 1);

    uint64_t key_b = std::min(n, m - 1);
    key_b = key_b << 32;
    key_b = key_b | std::max(m - 1, n);

    if (memo.find(key_a) == memo.end()) {
        memo[key_a] = uniquePaths(m, n - 1);
    }

    if (memo.find(key_b) == memo.end()) {
        memo[key_b] = uniquePaths(m - 1, n);
    }

    return memo[key_a] + memo[key_b];
}

int main() {
    std::cout << uniquePaths(3, 7) << '\n';
    return 0;
}