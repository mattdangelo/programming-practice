class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0.0;
        int current_time = customers[0][0];

        for(int i=0;i<customers.size();i++) {
            int ttc = customers[i][1];
            int waiting_time = max(current_time - customers[i][0], 0);
            current_time += ttc;
            total_waiting_time += (ttc + waiting_time);

            // Check if we have a gap between this customer and the next, and add
            // the time diff
            if((i < customers.size() - 1) && current_time < customers[i+1][0]) {
                current_time += (customers[i+1][0] - current_time);
            }
        }

        return total_waiting_time / customers.size();
    }
};
