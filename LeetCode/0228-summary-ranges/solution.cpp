class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> ret;
        
        if(nums.size() == 0) {
            return ret;
        }

        int start = nums[0];
        int end = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1] + 1) {
                end = nums[i];
            }
            else {
                if(start == end) {
                    ret.push_back(to_string(start));
                }
                else {
                    ret.push_back(to_string(start) + "->" + to_string(end));
                }
                
                start = nums[i];
                end = nums[i];
            }
        }
        
        if(start == end) {
            ret.push_back(to_string(start));
        }
        else {
            ret.push_back(to_string(start) + "->" + to_string(end));
        }
        
        
        return ret;
    }
};
