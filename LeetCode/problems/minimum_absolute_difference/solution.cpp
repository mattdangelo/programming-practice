class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        
        std::vector<std::vector<int>> res;
        int best_diff = INT32_MAX;
        
        for(int i=1;i<arr.size();i++) {
            int diff = abs(arr[i - 1] - arr[i]);
            if (diff < best_diff) {
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
                best_diff = diff;
            }
            else if(diff == best_diff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return res;
    }
};