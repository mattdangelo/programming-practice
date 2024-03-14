#define ASCII_OFFSET 97

class Solution {
    int ordering[26];
public:
    string customSortString(string order, string s) {
        for(int i=0;i<order.size();i++) {
            ordering[order[i] - ASCII_OFFSET] = i;
        }

        std::sort(s.begin(), s.end(), [this](const char& lhs, const char& rhs) {
            return ordering[lhs - ASCII_OFFSET] < ordering[rhs - ASCII_OFFSET];
        });

        return s;
    }
};
