class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> left = { nums[0] };
        std::vector<int> right = { nums[nums.size() - 1] };

        for(int i = 1; i < nums.size();i++) {
            left.push_back(left[i - 1] * nums[i]);
            right.push_back(right[i - 1] * nums[nums.size() - i - 1]);
        }

        std::vector<int> result;
        for(int i=0;i<nums.size();i++) {
            int l = i == 0 ? 1 : left[i - 1];
            int r = i == nums.size() - 1 ? 1 : right[nums.size() - i - 2];
            result.push_back(l * r);
        }

        return result;
    }
};
