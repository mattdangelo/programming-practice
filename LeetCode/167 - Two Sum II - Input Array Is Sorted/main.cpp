#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
	int l_ptr = 0;
	int r_ptr = numbers.size() - 1;
	int sum;

	while (l_ptr < r_ptr) {
		sum = numbers[l_ptr] + numbers[r_ptr];
		if (sum == target) {
			return {l_ptr + 1, r_ptr + 1};
		}
		else if (sum < target) {
			l_ptr++;
		}
		else {
			r_ptr--;
		}
	}

	return { -1, -1 };
}

int main() {
	std::vector<int> input = { 2, 7, 11, 15 };
	
	std::vector<int> res = twoSum(input, 9);

	std::cout << res[0] << " " << res[1] << std::endl;
	
	return 0;
}