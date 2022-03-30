class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int new_sum = 0;
            while(num) {
                new_sum += num % 10;
                num = num / 10;
            }
            num = new_sum;
        }
        
        return num;
    }
};