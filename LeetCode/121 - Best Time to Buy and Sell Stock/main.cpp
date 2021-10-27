#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    if(prices.size() < 2) {
        return 0;
    }

    std::vector<int> mins;
    std::vector<int> maxes;

    mins.push_back(prices[0]);
    maxes.push_back(prices[prices.size() - 1]);
    for(int i=1;i<prices.size();i++) {
        mins.push_back(prices[i] < mins[i-1] ? prices[i] : mins[i-1]);
        maxes.push_back(prices[prices.size() - i - 1] < maxes[i-1] ? maxes[i-1] : prices[prices.size() - i - 1]);
    }

    int max = 0;
    for(int i=1;i<prices.size();i++) {
        int val = maxes[prices.size() - 1 - i] - mins[i - 1];
        if(val > max) {
            max = val;
        }
    }

    return max;
}

int main() {
    std::vector<int> values = { 7, 1, 5, 3, 6, 4 };
    std::cout << maxProfit(values) << std::endl;
    return 0;
}