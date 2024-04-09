class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_map<int, int> found;

        int len = nums.size();

        // Early exit case
        if (len == 1 || len == 0) {
            return len;
        }

        int left = 0;
        found.emplace(nums[left], 1);

        for (int i = 1; i < len; i++) {
            if (found[nums[i]] != 2) {
                if (found[nums[i]] == 1) {
                    left++;
                    nums[left] = nums[i];
                    found[nums[i]] = 2;
                }
                else {
                    left++;
                    nums[left] = nums[i];
                    found[nums[i]] = 1;
                }
            }
        }

        return left + 1;
    }
};