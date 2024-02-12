class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        int thresh = nums.size() / 2;
        for(int i : nums) {
            if(counts.count(i)) {
                counts[i]++;
            }
            else {
                counts[i] = 1;
            }

            if(counts[i] > thresh) {
                return i;
            }
        }

        return -1;
    }
};