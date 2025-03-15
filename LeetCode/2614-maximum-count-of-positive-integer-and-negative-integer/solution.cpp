class Solution {
    enum Mode { LAST_NEGATIVE, FIRST_POSITIVE };
public:
    int maximumCount(vector<int>& nums) {
        int first_pos_index = index_bin_search(nums, FIRST_POSITIVE);
        int last_neg_index = index_bin_search(nums, LAST_NEGATIVE);

        int neg_count = (last_neg_index == -1) ? 0 : last_neg_index + 1;
        int pos_count = (first_pos_index == -1) ? 0 : nums.size() - first_pos_index;

        return std::max(neg_count, pos_count);
    }

    int index_bin_search(vector<int>& nums, Mode mode) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(mode == FIRST_POSITIVE) {
                if (nums[mid] > 0) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            else if(mode == LAST_NEGATIVE) {
                mid = left + (right - left + 1) / 2;

                if (nums[mid] < 0) {
                    left = mid;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        if (((mode == FIRST_POSITIVE) && nums[left] > 0) || 
            ((mode == LAST_NEGATIVE) && nums[left] < 0)) {
            return left;
        }

        return -1;
    }
};
