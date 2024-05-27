class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count[nums.size() + 1];
        for(int i=0;i<nums.size() + 1;i++) {
            count[i] = 0;
        }

        for(int i : nums) {
            int index = std::min((int)nums.size(), i);
            count[index]++;
        }

        int total_right = 0;
        for(int i=nums.size();i>=0;i--) {
            total_right += count[i];
            if(i == total_right) {
                return total_right;
            }
        }

        return -1;
    }
};
