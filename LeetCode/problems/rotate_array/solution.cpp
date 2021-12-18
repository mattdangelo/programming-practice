class Solution {
    void swap(std::vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
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
};