class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int highest = -1;
        int second_highest = -1;
        for(int i : nums) {
            if(i >= highest) {
                second_highest = highest;
                highest = i;
            }
            else if(i > second_highest) {
                second_highest = i;
            }
        }

        return (highest - 1) * (second_highest - 1);
    }
};