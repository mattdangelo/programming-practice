class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::unordered_set<int> found;

        for(int i=0;i<nums.size();i++) {
            found.insert(nums[i]);
        }
        
        std::vector<int> missing;
        for(int i=1;i<nums.size() + 1;i++) {
            if(found.find(i) == found.end()) {
                missing.push_back(i);
            }
        }
        return missing;
    }
};