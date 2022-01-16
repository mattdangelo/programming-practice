class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_start_end_dist = 0;
        while(!seats[max_start_end_dist]) {
            max_start_end_dist++;
        }
        
        int i = seats.size() - 1;
        while(!seats[i]) {
            i--;
            max_start_end_dist = std::max(max_start_end_dist, (int)(seats.size() - 1 - i));
        }

        int end = 0;
        int count = 0;
        int best = 0;
        while(end < seats.size()) {
            if(seats[end]) {
                best = std::max(best, count);
                count = 0;
            }
            else {
                count++;
            }
            end++;
        }
        
        return std::max((best + 1) / 2, max_start_end_dist);
    }
};
