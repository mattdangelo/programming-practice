class Solution {
public:
    void rec_permute(vector<int> nums, int i, std::set<vector<int>>& res) {
        if (i == nums.size()) {
            res.insert(nums);
        } 
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                rec_permute(nums, i + 1, res);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::set<std::vector<int>> res;
        rec_permute(nums , 0, res);
        std::vector<std::vector<int>> ret;
        for(std::vector<int> v : res) {
            ret.push_back(v);
        }
        return ret;
    }
};