#define MIN_VALUE -100
#define MAX_VALUE 100

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Records the frequencies of the values in the array
        // Note that we offset negative values so they start at 0
        // So -100 -> 0, 100 -> 200, etc...
        int frequency[MAX_VALUE - MIN_VALUE + 1] = { 0 };

        for(int i : nums) {
            frequency[i + -MIN_VALUE]++;
        }

        std::sort(nums.begin(), nums.end(), [&frequency](const int& lhs, const int& rhs) {
            int& lhs_freq = frequency[lhs + -MIN_VALUE];
            int& rhs_freq = frequency[rhs + -MIN_VALUE];
            if(lhs != rhs && lhs_freq == rhs_freq) {
                // Sort normally in decreasing orderif the values are different but 
                // frequencies are the same
                return lhs > rhs;
            }
            else {
                // Sort by frequencies in increasing order
                return lhs_freq < rhs_freq;
            }
        });

        return nums;
    }
};
