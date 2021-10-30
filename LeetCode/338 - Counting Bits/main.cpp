#include <iostream>
#include <vector>

std::vector<int> countBits(int n) {
    std::vector<int> result(n + 1, 0);
    for(unsigned int i=1;i<=n;i++) {
        int res = result[i >> 1];
        if(i&1) {
            res++;
        }
        result[i] = res;
    }

    return result;
}

int main() {
    std::vector<int> result = countBits(5);

    for(int i : result) {
        std::cout << i << std::endl;
    }

    return 0;
}