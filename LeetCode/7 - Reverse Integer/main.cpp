#include <iostream>
#include <cmath>
#include <string>

int reverse(int x) {
    bool negative = x < 0;
    std::string str_val = std::to_string(x);
    if(negative) {
        str_val = str_val.substr(1, str_val.length() - 1);
    }

    if(str_val.length() == 1) {
        return std::stoi(str_val);
    }

    int left = 0;
    int right = str_val.length() - 1;

    while(left < right) {
        char temp = str_val[left];
        str_val[left] = str_val[right];
        str_val[right] = temp;
        left++;
        right--;
    }

    long value = std::stol(str_val);

    if((negative && value > pow(2, 31)) || (!negative && value > (pow(2, 31) - 1))) {
        return 0;
    }

    return negative ? -value : value;
}

int main() {
    std::cout << reverse(123) << std::endl;
}