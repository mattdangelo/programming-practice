class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    while (left < right) {
        int diff = numbers.at(right) + numbers.at(left);
        if (diff < target) {
            left++;
        }
        else if (diff > target) {
            right--;
        }
        else {
            return std::vector<int> {left + 1, right + 1};
        }
    }

    return std::vector<int>();
    }
};
