class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        std::string val = "";
        val.reserve(16);
        for(int i=0;i<nums.size();i++) {
            val.push_back(nums[i][i] == '0' ? '1' : '0');
        }

        return val;
    }
};
