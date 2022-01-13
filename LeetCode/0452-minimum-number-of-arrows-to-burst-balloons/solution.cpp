class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](std::vector<int>& a, std::vector<int>& b) { return a[0] < b[0]; });

        int count = 1;
        int end = points[0][1];
        for(int i=1;i<points.size();i++) {
            if(points[i][0] > end) {
                count++;
                end = points[i][1];
            }
            else {
                end = std::min(end, points[i][1]);
            }
        }
        
        return count;
    }
};
