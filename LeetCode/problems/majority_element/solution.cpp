class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_threshold = nums.size() / 2;
        std::unordered_map<int, int> counts;
        for(int n : nums) {
            if(counts.count(n) == 0) {
                counts[n] = 1;
            }
            else {
                counts[n]++;
            }

            if(counts[n] > maj_threshold) {
                return n;
            }
        }

        // Should never happen
        return -1;
    }
};