class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> squared(nums.size());
        
        // O(n)
        for(int i = 0;i<nums.size();i++) {
            squared[i] = nums[i] * nums[i];
        }
        
        // O(n log (n))
        std::sort(squared.begin(), squared.end());
        return squared;
    }
};