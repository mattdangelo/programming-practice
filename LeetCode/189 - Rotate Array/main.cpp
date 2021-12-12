#include <iostream>
#include <vector>

void swap(std::vector<int>& nums, int i, int j) {
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void rotate(std::vector<int>&nums, int k) {
	k = k % nums.size();

	for (int i = 0; i < nums.size() / 2; i++) {
		swap(nums, i, nums.size() - 1 - i);
	}

	for (int i = 0; i < k / 2; i++) {
		swap(nums, i, k - i - 1);
	}

	for (int i = 0; i < (nums.size() - k) / 2; i++) {
		swap(nums, i + k, nums.size() - 1 - i);
	}
}

int main() {
	std::vector<int> input = { 1, 2, 3, 4, 5, 6, 7 };

	rotate(input, 3);

	for (int i : input) {
		std::cout << i << " " << std::endl;
	}

	return 0;
}