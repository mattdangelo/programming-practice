#include <iostream>

int hammingWeight(uint32_t n) {
    int count = 0;
    while(n) {
        if(n & 1) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main() {
    std::cout << hammingWeight(11) << std::endl;
    return 0;
}