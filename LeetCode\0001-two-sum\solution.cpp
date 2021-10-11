class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i=0;i<size;i++) {
            for(int j=i+1;j<size;j++) {
                if(nums.at(j) == target - nums.at(i)) {
                    std::vector<int> indicies;
                    indicies.push_back(i);
                    indicies.push_back(j);
                    return indicies;
                }
            }
        }
        std::vector<int> error;
        return error;
    }
};
