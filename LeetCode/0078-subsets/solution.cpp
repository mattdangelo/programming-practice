class Solution {
    std::set<std::vector<int>> results;
    std::vector<int> working_vector;
    void recSubsets(std::vector<int>& nums, std::vector<int>& working_vector, int idx) {
        if(idx == nums.size()) {
            results.insert(working_vector);
            return;
        }

        // Take the element
        working_vector.push_back(nums[idx]);
        recSubsets(nums, working_vector, idx + 1);
        
        // Don't take the element
        working_vector.pop_back();
        recSubsets(nums, working_vector, idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        working_vector.reserve(nums.size());
        recSubsets(nums, working_vector, 0);

        std::vector<std::vector<int>> ret;
        ret.reserve(results.size());
        ret.assign(results.begin(), results.end());

        return ret;
    }
};
