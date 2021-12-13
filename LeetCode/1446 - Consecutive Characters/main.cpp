#include <iostream>

int maxPower(std::string s) {
    int global_max = 1;
    int local_max = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            local_max++;
        }
        else {
            global_max = std::max(local_max, global_max);
            local_max = 1;
        }
    }

    global_max = std::max(local_max, global_max);

    return global_max;
}

int main() {
    std::cout << maxPower("leetcode") << std::endl;
	return 0;
}