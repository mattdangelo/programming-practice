class Solution {
public:
    void rec_permute(vector<int> nums, int i, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(nums);
        } 
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                rec_permute(nums, i + 1, res);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> res;
        rec_permute(nums , 0, res);
        return res;
    }
};
