#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>&points, int k) {
    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            return (a.at(0) * a.at(0) + a.at(1) * a.at(1)) < (b.at(0) * b.at(0) + b.at(1) * b.at(1));
        });


    return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
}

int main() {
    std::vector<std::vector<int>> input = {
        {1, 3},
        {-2, 2}
    };

    std::vector<std::vector<int>> res = kClosest(input, 1);
    for (std::vector<int> i : res) {
        std::cout << i.at(0) << " " << i.at(1) << std::endl;
    }
}