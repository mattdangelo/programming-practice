#include <iostream>

int arrangeCoins(int n) {
    if(n == 0) {
        return 0;
    }

    int i = 1;

    while(n - i >= 0) {
        n -= i;
        i++;
    }

    return i - 1;
}

int main() {
    std::cout << arrangeCoins(8) << std::endl;
    return 0;
}