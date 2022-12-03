class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        std::map<int, int> values;
        std::sort(changed.begin(), changed.end());
        
        // populate
        for(int i : changed) {
            if(values.count(i) == 0) {
                values[i] = 1;
            }
            else {
                values[i]++;
            }
        }
        
        std::vector<int> res;
        res.reserve(changed.size() / 2);
        while(!values.empty()) {
            int original = values.begin()->first;
            
            if(values[original] > 1) {
                values[original]--;
            }
            else {
                values.erase(original);
            }
            
            if(values.count(original * 2) == 0) {
                std::vector<int> empty;
                return empty;
            }
            else {
                res.push_back(original);
                if(values[original * 2] > 1) {
                    values[original * 2]--;
                }
                else {
                    values.erase(original * 2);
                }
            }
        }
        
        return res;
    }
};