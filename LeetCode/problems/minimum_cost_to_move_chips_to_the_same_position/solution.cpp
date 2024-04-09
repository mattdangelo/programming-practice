class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        if(position.size() == 0) {
            return 0;
        }

        int count[2] = {0, 0};
        
        for(int i : position) {
            count[i%2]++;
        }
        
        return min(count[0], count[1]);
    }
};