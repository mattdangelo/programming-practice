class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time_taken = 0;
        while(tickets[k] > 0) {
            // Go through everyone in the list
            for(int i=0;i<tickets.size();i++) {
                // If they still have tickets to buy
                if(tickets[i] > 0) {
                    // Buy them
                    tickets[i]--;
                    time_taken++;

                    // Check if our condition is met
                    if(i == k && tickets[k] == 0) {
                        return time_taken;
                    }
                }
            }
        }

        return time_taken;
    }
};
