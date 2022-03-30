class Solution {
    struct vertex {
        int value;
        int arrays_index;
    };
    
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_diff = INT32_MIN;
        std::vector<vertex> maxes;
        std::vector<vertex> mins;
        
        for(int i = 0;i<arrays.size();i++) {
            mins.push_back({.value = arrays[i][0], .arrays_index = i});
            maxes.push_back({.value = arrays[i][arrays[i].size() - 1], .arrays_index = i});
        }
        
        std::sort(maxes.begin(), maxes.end(),
            [](const vertex & a, const vertex & b) -> bool
        { 
            return a.value > b.value;
        });
        
        std::sort(mins.begin(), mins.end(),
            [](const vertex & a, const vertex & b) -> bool
        { 
            return a.value < b.value;
        });

        if(maxes[0].arrays_index != mins[0].arrays_index) {
            return abs(maxes[0].value - mins[0].value);
        }
        else {
            return max(abs(maxes[0].value - mins[1].value), abs(maxes[1].value - mins[0].value));
        }
        
    }
};