class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int i : nums) {
            if (seen.find(i) != seen.end()) {
                return true;
            }
            else {
                seen.insert(i);
            }
        }

        return false;
    }
};