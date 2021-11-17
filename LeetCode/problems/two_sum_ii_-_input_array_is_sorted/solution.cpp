class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum == target) {
                std::vector<int> res = {l + 1, r + 1};
                return res;
            }
            else if(sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
        
        return std::vector<int>();
    }
};