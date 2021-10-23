class Solution {
public:
    int findMin(vector<int>& nums) {
        int prev = 0;
        int lowest = 5001;
        for(int i : nums) {
            if(i < lowest) {
                lowest = i;
                prev = i;
            }
            else if(i < prev) {
                break;
            }
        }

        return lowest;
    }
};
