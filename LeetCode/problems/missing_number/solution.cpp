class Solution {
public:
    int missingNumber(vector<int>& nums) {
    int sum = 0;
    int size = nums.size();
    for (int i = 0; i < size + 1;i++) {
        sum += i;
        if (i != size) {
            sum -= nums.at(i);
        }
    }

    return sum;
    }
};