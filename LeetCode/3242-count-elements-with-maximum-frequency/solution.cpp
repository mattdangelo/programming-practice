class Solution {
    std::unordered_map<int, int> counts;
public:
    int maxFrequencyElements(vector<int>& nums) {
        int highest = 1;
        for(int i : nums) {
            if(counts.count(i)) {
                counts[i]++;
                highest = std::max(highest, counts[i]);
            }
            else {
                counts[i] = 1;
            }
        }

        int count = 0;
        for(std::pair<int, int> p : counts) {
            if(p.second == highest) {
                count += p.second;
            }
        }
        return count;
    }
};
