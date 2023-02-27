class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Trivial case, size == 1
        if(nums.size() == 1) {
            return nums[0];
        }

        // Perform binary search
        int left = 0;
        int right = nums.size();
        int mid;

        while(true) {
            mid = left + (right - left) / 2;
            
            if(isSingleElement(nums, mid)) {
                return nums[mid];
            }

            if(singleElementHasAlreadyOccurred(nums, mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
    }
private:
    bool singleElementHasAlreadyOccurred(vector<int>& nums, int index) {
        if(index % 2 == 0) {
            return nums[index + 1] != nums[index];
        }
        else {
            if(index + 1 == nums.size()) {
                return true;
            }

            return nums[index + 1] == nums[index];
        }
    }

    bool isSingleElement(vector<int>& nums, int index) {
        if(index - 1 < 0) {
            return nums[index] != nums[index + 1];
        }

        if(index + 1 == nums.size()) {
            return nums[index] != nums[index - 1];
        }

        return (nums[index] != nums[index - 1]) && (nums[index] != nums[index + 1]);
    }
};
