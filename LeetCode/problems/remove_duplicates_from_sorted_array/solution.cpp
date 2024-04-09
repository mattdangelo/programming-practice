class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();

        // Early exit case
        if (len == 1 || len == 0) {
            return len;
        }

        int left = 0;

        for (int i = 1; i < len; i++) {
            if (nums[left] != nums[i]) {
                left++;
                nums[left] = nums[i];
            }
        }

        return left + 1;
    }
};