class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> found;
        for(int i=0;i<nums.size();i++) {
            int curr = nums[i];
            if(found.count(curr)) {
                if(abs(found[curr] - i) <= k) {
                    return true;
                }
                else {
                    found[curr] = i;
                }
            }
            else {
                found[curr] = i;
            }
        }
        
        return false;
    }
};
