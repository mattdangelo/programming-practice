class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;    
        }
        
        long pow = 1;
        int num_c = n;
        while(num_c) {
            num_c = num_c >> 1;
            pow = pow << 1;   
        }
        return n ^ (pow - 1);
    }
};
