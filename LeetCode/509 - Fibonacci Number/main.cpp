#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;

int fib(int n) {
	if (n < 2) {
		return n;
	}

	if (memo.count(n - 1) == 0) {
		memo[n - 1] = fib(n - 1);
	}

	if (memo.count(n - 2) == 0) {
		memo[n - 2] = fib(n - 2);
	}

	return memo[n - 1] + memo[n - 2];
}

int main() {
	std::cout << fib(2) << std::endl;
	return 0;
}