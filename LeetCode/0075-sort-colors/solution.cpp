class Solution {
    inline void swap(vector<int>& nums, int i, int j) {
        if(i == j) return;

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int moveToIndex(vector<int>& nums, int starting_index, int target_value) {
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != target_value) {
                continue;
            }
            else {
                swap(nums, i, starting_index);
                starting_index++;
            }
        }

        return starting_index;
    }
public:
    void sortColors(vector<int>& nums) {
        // Move all 0s to the start, then move all 1s to the index after the last 0
        moveToIndex(nums, moveToIndex(nums, 0, 0), 1);
    }
};
