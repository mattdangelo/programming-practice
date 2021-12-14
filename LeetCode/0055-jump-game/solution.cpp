class Solution {
public:
    bool canJump(vector<int>& nums) {
        int best = 0;
        for(int i=0;i<=best;i++) {
            best = max(best, i + nums[i]);
            if(best >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};
