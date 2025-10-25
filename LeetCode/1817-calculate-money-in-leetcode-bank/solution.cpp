class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int week = 0;
        int day_of_week = 0;

        while(n > 0) {
            total += day_of_week + 1 + week;
            n--;
            day_of_week = (day_of_week + 1) % 7;
            if(day_of_week == 0) {
                week++;
            }
        }

        return total;
    }
};
