class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> prq;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
           return a[0] < b[0]; 
        });
        
        int max_count = 0;
        int current_count = 0;
        int t_ptr = 0;
        
        for(int i=0;i<intervals.size();i++) {
            t_ptr = intervals[i][0];

            while(!prq.empty() && (prq.top() <= t_ptr)) {
                prq.pop();
                current_count--;
            }            
            
            prq.push(intervals[i][1]);
            current_count++;
            max_count = std::max(max_count, current_count);
        }
        
        return max_count;
    }
};