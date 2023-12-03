class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // Special case - only 1 point in the list, don't need to travel
        if(points.size() == 1) {
            return 0;
        }

        int time_taken = 0;
        int next_index = 1;
        int target_x = points[next_index][0];
        int target_y = points[next_index][1];

        int current_x = points[0][0];
        int current_y = points[0][1];

        while(next_index < points.size()) {
            if(target_x == current_x && target_y == current_y) {
                // We're at the next point, start moving toward the next next one
                next_index++;
                if(next_index == points.size()) {
                    break;
                }
                target_x = points[next_index][0];
                target_y = points[next_index][1];
            }
            else {
                // Move
                if(current_x != target_x) {
                    current_x += current_x < target_x ? 1 : -1;
                }

                if(current_y != target_y) {
                    current_y += current_y < target_y ? 1 : -1;
                }

                time_taken++;
            }
        }

        return time_taken;
    }
};
