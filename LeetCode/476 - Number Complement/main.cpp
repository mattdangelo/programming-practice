#include <iostream>

int findComplement(int num) {
    long pow = 1;
    int num_c = num;
    while (num_c) {
        num_c = num_c >> 1;
        pow = pow << 1;
    }
    return num ^ (pow - 1);
}

int main() {
    std::cout << findComplement(5) << std::endl;
}