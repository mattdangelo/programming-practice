class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }

        int left = 0;
        int count = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            if(nums[right] == val) {
                right--;
            }
            else if(nums[left] != val) {
                left++;
            }
            else {
                nums[left] = nums[right];
                right--;
                left++;
                count++;
            }
        }
        return left;
    }
};
