class Solution {
public:
    int minOperations(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        int ops = 0;

        for(int i : nums) {
            if(counts.count(i)) {
                counts[i]++;
            }
            else {
                counts[i] = 1;
            }
        }

        for(std::pair<int, int> p : counts) {
            if(p.second == 1) {
                return -1;
            }
            else {
                ops += ceil(p.second / 3.0);
            }
        }

        return ops;
    }
};
