#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int>& cost) {
    std::vector<int> memo(cost.size());
    memo[0] = cost[0];
    memo[1] = cost[1];

    for(int i=2;i< memo.size();i++) {
        memo[i] = std::min(memo[i - 1] + cost[i], memo[i - 2] + cost[i]);
    }

    return std::min(memo[memo.size() - 1], memo[memo.size() - 2]);
}

int main() {
    std::vector<int> input = { 1,100,1,1,1,100,1,1,100,1 };
    std::cout << minCostClimbingStairs(input) << std::endl;
}
