#include <iostream>

int target;

int guess(int g) {
    if(target < g) {
        return -1;
    }
    else if(target > g) {
        return 1;
    }
    else {
        return 0;
    }
}

int guessNumber(int n) {
    int ceil = n;
    int floor = 0;

    while(ceil != floor) {
        int g = (ceil + (long)floor) / 2;
        int i = guess(g);
        if(i == -1) {
            ceil = g;
        }
        else if(i == 1) {
            floor = g + 1;
        }
        else {
            return g;
        }
    }

    return ceil;
}

int main() {
    target = 6;
    std::cout << guessNumber(10) << std::endl;
}