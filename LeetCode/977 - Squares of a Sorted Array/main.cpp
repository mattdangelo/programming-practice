#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortedSquares(std::vector<int>& nums) {
	int first_pos = -1;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] >= 0) {
			first_pos = i;
			break;
		}
	}
	std::vector<int> ret(nums.size());

	if (first_pos == 0) {
		for (int i = 0; i < nums.size();i++) {
			ret[i] = nums[i] * nums[i];
		}
	}
	else if (first_pos == -1) {
		for (int i = 0; i < nums.size(); i++) {
			ret[nums.size() - 1 - i] = nums[i] * nums[i];
		}
	}
	else {
		int l_ptr = first_pos - 1;
		int r_ptr = first_pos;

		int i = 0;
		while (l_ptr >= 0 || r_ptr < nums.size()) {
			if (l_ptr < 0) {
				ret[i] = nums[r_ptr] * nums[r_ptr];
				r_ptr++;
			}
			else if (r_ptr == nums.size()) {
				ret[i] = nums[l_ptr] * nums[l_ptr];
				l_ptr--;
			}
			else {
				if (abs(nums[l_ptr]) < abs(nums[r_ptr])) {
					ret[i] = nums[l_ptr] * nums[l_ptr];
					l_ptr--;
				}
				else {
					ret[i] = nums[r_ptr] * nums[r_ptr];
					r_ptr++;
				}
			}

			i++;
		}
	}

	return ret;
}

int main() {
	std::vector<int> input = { -2, -1, 3 };
	auto res = sortedSquares(input);

	for (int i : res) {
		std::cout << i << " ";
	}

	return 0;
}