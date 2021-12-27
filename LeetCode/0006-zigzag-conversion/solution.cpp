class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        std::string* rows = new std::string[numRows];

        bool rising = false;
        int rowptr = 0;
        for (int i = 0; i < s.length(); i++) {
            if (rising) {
                rowptr--;
                rows[rowptr].push_back(s[i]);
                if (rowptr == 0) {
                    rising = false;
                    rowptr++;
                }
            }
            else {
                rows[rowptr].push_back(s[i]);
                if (rowptr == numRows - 1) {
                    rising = true;
                }
                else {
                    rowptr++;
                }
            }
        }

        std::string ret = "";
        for (int i = 0; i < numRows;i++) {
            ret += rows[i];
        }
        return ret;
    }
};
