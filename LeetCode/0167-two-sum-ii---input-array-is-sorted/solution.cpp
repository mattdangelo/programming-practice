class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
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
};
