class Solution {
public:
    int findComplement(int num) {
        long pow = 1;
        int num_c = num;
        while(num_c) {
            num_c = num_c >> 1;
            pow *= 2;   
        }
        return (num ^ (pow - 1));
    }
};
