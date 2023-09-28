class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), []( const int& lhs, const int& rhs) {
            return (lhs % 2) < (rhs % 2);
        });

        return nums;
    }
};
