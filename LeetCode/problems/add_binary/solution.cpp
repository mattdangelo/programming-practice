class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        bool carry = false;
        int a_ptr = a.length() - 1;
        int b_ptr = b.length() - 1;
        bool a_val;
        bool b_val;
        while(a_ptr >= 0 || b_ptr >= 0) {
            a_val = a_ptr < 0 ? false : a[a_ptr] == '1';
            b_val = b_ptr < 0 ? false : b[b_ptr] == '1';
            res = (((a_val ^ b_val) ^ carry) ? '1' : '0') + res;
            carry = (a_val & b_val) || (a_val & carry) || (b_val & carry);
            a_ptr--;
            b_ptr--;
        }
        
        if(carry) {
            res = "1" + res;
        }
        
        return res;
    }
};