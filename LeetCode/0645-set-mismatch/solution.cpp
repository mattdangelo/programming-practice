class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> seen;
        int count = 0;
        int dup = 0;
        for(int i=0;i<n;i++) {
            count+= nums[i];
            if(seen.count(nums[i])) {
                dup = nums[i];
            }
            else {
                seen.insert(nums[i]);
            }
        }
        
        return {dup, (((n + 1) * n) / 2) - (count - dup) };
    }
};
