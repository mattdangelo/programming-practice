class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int net[1001] = {0};
        for(std::vector<int> i : trips) {
            net[i[1]] += i[0];
            net[i[2]] -= i[0];
        }
        int count = 0;
        for(int i=0;i<1001;i++) {
            count += net[i];
            if(count > capacity) {
                return false;
            }
        }
        
        return true;
    }
};
