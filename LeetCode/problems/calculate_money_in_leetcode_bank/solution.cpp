class Solution {
public:
    int totalMoney(int n) {
        int count = -1;
        int sum = 0;
        for(int i=0;i<n;i++) {
            if(i%7==0) {
                count++;
            }
            sum += (i%7+1)+count;
        }

        return sum;
    }
};