class Solution {
public:
    int myAtoi(string s) {
        int ptr = 0;
        while(s[ptr] == ' ') {
            ptr++;
        }

        bool positive = true;

        if(s[ptr] == '-') {
            positive = false;
            ptr++;
        }
        else if(s[ptr] == '+') {
            ptr++;
        }

        bool started_value = false;
        std::string value;
        while(std::isdigit(s[ptr])) {
            if(s[ptr] != '0' || started_value) {
                value += s[ptr];
                started_value = true;
            }
            ptr++;
        }

        if(value.length() > 10) {
            // We have to clamp anyway
            return positive ? INT32_MAX : INT32_MIN;
        }
        else {
            // Translate string to translated, check if we have to clamp, then return
            long translated = 0;
            long multiplier = 1;
            for(int i=value.length()-1;i>=0;i--) {
                translated += multiplier * (value[i] - '0');
                multiplier = multiplier * 10;
            }

            if(positive) {
                translated = std::min((long)INT32_MAX, translated);
            }
            else {
                translated = std::min(((long)INT32_MAX + 1), translated);
            }

            return positive ? (int)translated : (int)(-translated);
        }
    }
};
