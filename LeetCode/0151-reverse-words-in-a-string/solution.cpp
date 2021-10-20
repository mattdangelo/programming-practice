class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        string buffer = "";
        int len = s.length();
        for (int i = 0; i < len;i++) {
            if (s[i] == ' ') {
                if (buffer.length() > 0) {
                    tokens.push_back(buffer);
                    buffer = "";
                }
            }
            else {
                buffer += s[i];
            }
        }

        if (buffer.length() > 0) {
            tokens.push_back(buffer);
            buffer = "";
        }


        for (int i = 0; i < tokens.size(); i++) {
            buffer += tokens.at(tokens.size() - i - 1);
            if (i != tokens.size() - 1) {
                buffer += ' ';
            }
        }

        return buffer;
    }
};
