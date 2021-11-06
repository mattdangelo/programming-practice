#include <iostream>
#include <vector>

std::vector<int> singleNumber(std::vector<int>& nums) {
    long xor_res = 0;

    for(int i : nums) {
        xor_res ^= i;
    }

    // At this point, we have a ^ b in xor_res
    // We know that if a ^ b has a 1 in bit i, the values between the two were different.

    xor_res &= -xor_res;

    int bit_set_res = 0;
    int bit_not_set_res = 0;

    for(int i : nums) {
        if(i & xor_res) {
            // Bit is set
            bit_set_res ^= i;
        }
        else {
            // Not set
            bit_not_set_res ^= i;
        }
    }

    return { bit_set_res, bit_not_set_res };
}

int main() {
    std::vector<int> input = { 1, 2, 1, 3, 2, 5 };
    auto res = singleNumber(input);
    std::cout << res[0] << " " << res[1] << std::endl;

    return 0;
}