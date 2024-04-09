class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
           return a[0] < b[0];
        });
        
        int prev_end = -1;
        for(std::vector<int> i : intervals) {
            if(i[0] < prev_end) {
                return false;
            }
            
            prev_end = i[1];
        }
        
        return true;
    }
};