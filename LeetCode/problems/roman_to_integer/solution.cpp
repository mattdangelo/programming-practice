class Solution {
    const std::unordered_map<char, int> values = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
public:
    int romanToInt(string s) {
        std::vector<std::string> tokens;
        int total = 0;
        int ptr = 1;

        std::string buffer = s.substr(0, 1);
        while(ptr < s.length()) {
            if(values.at(buffer[buffer.size() - 1]) >= values.at(s[ptr])) {
                int temp = values.at(buffer.at(buffer.length() - 1));
                for(int i = buffer.length() - 2; i>=0;i--) {
                    temp -= values.at(buffer[i]);
                }
                total += temp;
                buffer = "";
            }
            buffer += s[ptr];
            ptr++;
        }
        
        int temp = values.at(buffer.at(buffer.length() - 1));
        for(int i = buffer.length() - 2; i>=0;i--) {
            temp -= values.at(buffer[i]);
        }
        total += temp;
        
        return total;
    }
};