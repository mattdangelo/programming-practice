#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int tribonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n < 3) {
		return 1;
	}

	if (memo.count(n - 1) == 0) {
		memo[n - 1] = tribonacci(n - 1);
	}

	if (memo.count(n - 2) == 0) {
		memo[n - 2] = tribonacci(n - 2);
	}

	if (memo.count(n - 3) == 0) {
		memo[n - 3] = tribonacci(n - 3);
	}

	return memo[n - 1] + memo[n - 2] + memo[n - 3];
}

int main() {
	std::cout << tribonacci(4) << std::endl;
	return 0;
}