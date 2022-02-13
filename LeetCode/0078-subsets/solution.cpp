class Solution {
    std::vector<std::vector<int>> ss;
public:
    void recPopulateSubsets(std::vector<int>& nums, std::vector<int> current, int index) {
        if(index == nums.size()) {
            ss.push_back(current);
        }
        else {
            recPopulateSubsets(nums, current, index + 1);
            current.push_back(nums[index]);
            recPopulateSubsets(nums, current, index + 1);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        recPopulateSubsets(nums, std::vector<int>(), 0);
        return ss;
    }
};
