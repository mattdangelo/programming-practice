class Solution {
public:
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++) {
        for(int j=i+1;j<nums.size();j++) {
            if(nums.at(j) == target - nums.at(i)) {
                std::vector<int> indices;
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }

    std::vector<int> error = { INT32_MAX, INT32_MAX };
    return error;
}
};