class Solution {
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> results;
        std::sort(intervals.begin(), intervals.end(), 
            [](const std::vector<int> & a, const std::vector<int> & b) -> bool
        { 
            return a[0] < b[0]; 
        });
        
        results.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= results[results.size() - 1][1]) {
                results[results.size() - 1][1] = std::max(intervals[i][1], results[results.size() - 1][1]);
            }
            else {
                results.push_back(intervals[i]);
            }
        }
        
        return results;
    }
};
