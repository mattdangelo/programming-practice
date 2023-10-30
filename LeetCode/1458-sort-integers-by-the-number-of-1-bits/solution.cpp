class Solution {
public:
    static int num_of_1_bits(const int& val) {
        int total = 0;
        for(int i=0;i<32;i++) {
            if(val & (1 << i)) {
                total++;
            }
        }

        return total;
    }

    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), [this](const int& lhs, const int& rhs) {
           int lhs_bit_count = num_of_1_bits(lhs);
           int rhs_bit_count = num_of_1_bits(rhs);

           if(lhs_bit_count == rhs_bit_count) {
               return lhs < rhs;
           }
           else if(lhs_bit_count < rhs_bit_count) {
               return true;
           }

           return false;
        });

        return arr;
    }
};
