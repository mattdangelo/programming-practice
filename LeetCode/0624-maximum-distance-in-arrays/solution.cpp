class Solution {
    struct ArraySummary {
        int index = -1;
        int min = INT_MAX;
        int max = INT_MIN;
    };

public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Get the smallest 2 and largest 2 elements (by values) in the list
        ArraySummary smallest[2];
        ArraySummary largest[2];
    
        for(int i=0;i<arrays.size();i++) {
            ArraySummary summary = { .index = i, 
                                     .min = arrays[i].front(), 
                                     .max = arrays[i].back() };

            if(summary.min < smallest[0].min) {
                smallest[1] = smallest[0];
                smallest[0] = summary;
            }
            else if(summary.min < smallest[1].min) {
                smallest[1] = summary;
            }

            if(summary.max > largest[0].max) {
                largest[1] = largest[0];
                largest[0] = summary;
            }
            else if(summary.max > largest[1].max) {
                largest[1] = summary;
            }
        }

        if(largest[0].index != smallest[0].index) {
            // Easy case - the largest and small elements come
            // from different arrays, just take the difference
            return abs(smallest[0].min - largest[0].max);
        }
        else {
            // Largest and smallest come from the same array
            // Try combinations from the second smallest / largest
            return std::max(abs(smallest[0].min - largest[1].max),
                            abs(smallest[1].min - largest[0].max));
        }

        return 0;
    }
};
