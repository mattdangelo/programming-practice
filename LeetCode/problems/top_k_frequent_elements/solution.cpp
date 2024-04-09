class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        
        for(int i : nums) {
            if(counts.count(i)) {
                counts[i]++;
            }
            else {
                counts[i] = 1;
            }
        }
        
        vector<std::pair<int, int>> count_vec { counts.begin(), counts.end() };
        
        std::sort(count_vec.begin(), count_vec.end(), []( const std::pair<int, int>& lhs, const  std::pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        });
        
        std::vector<int> results(k);
        
        for(int i=0;i<k;i++) {
            results[i] = count_vec[i].first;
        }
        
        return results;
    }
};