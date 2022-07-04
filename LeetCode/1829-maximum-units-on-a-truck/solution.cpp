class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        std::sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
           return lhs[1] > rhs[1]; 
        });
        
        int total_box_count = 0;
        int total = 0;
        int ptr = 0;
        while(ptr < boxTypes.size() && total_box_count < truckSize) {
            if(boxTypes[ptr][0] == 0) {
                  ptr++;
            }
            else {
                total += boxTypes[ptr][1];
                boxTypes[ptr][0]--;
                total_box_count++;
            }
        }
        
        return total;
    }
};
