class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        std::vector<int> leftsum(nums.size());
        std::vector<int> rightsum(nums.size());
        
        leftsum[0] = nums[0];
        rightsum[nums.size() - 1] = nums[nums.size() - 1];
        
        for(int i=1;i<nums.size();i++) {
            leftsum[i] = leftsum[i - 1] + nums[i];
            rightsum[nums.size() - 1 - i] =  rightsum[nums.size() - i] + nums[nums.size() - 1 - i];
        }
        
        for(int i=0;i<nums.size();i++) {
            if(leftsum[i] == rightsum[i]) {
                return i;
            }            
        }

        return -1;
    }
};
