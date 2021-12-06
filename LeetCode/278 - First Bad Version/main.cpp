#include <iostream>

bool isBadVersion(int n) {
	return n >= 4;
}

int firstBadVersion(int n) {
	int left = 0;
	int right = n;
	int mid;

	while (left <= right) {
		mid = left - (right + left) / 2;
		if (isBadVersion(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return left;
}

int main() {
	std::cout << firstBadVersion(5) << std::endl;
	return 0;
}