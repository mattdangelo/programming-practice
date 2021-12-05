class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ptr = digits.size() - 1;
        digits[ptr] = (digits[ptr] + 1) % 10;

        while(digits[ptr] == 0) {
            if(ptr <= 0) {
                vector<int> new_vec(digits.size() + 1);
                new_vec[0] = 1;
                for(int i=0;i<digits.size();i++) {
                    new_vec[i + 1] = digits[i];
                }
                return new_vec;
            }
            else {
                ptr--;
                digits[ptr] = (digits[ptr] + 1) % 10;
            }
        }
        
        return digits;
    }
};