class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj_threshold = nums.size() / 3;
        std::unordered_map<int, int> counts;
        for(int n : nums) {
            if(counts.count(n) == 0) {
                counts[n] = 1;
            }
            else {
                counts[n]++;
            }
        }

        std::vector<int> res;
        for(auto p : counts) {
            if(p.second > maj_threshold) {
                res.push_back(p.first);
            }
        }
        
        return res;
    }
};