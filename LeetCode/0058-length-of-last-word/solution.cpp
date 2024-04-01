class Solution {
public:
    int lengthOfLastWord(string s) {
        std::string buffer = "";
        for(int i=s.length()-1;i>=0;i--) {
            if(s[i] == ' ') {
                if(buffer.length() == 0) {
                    continue;
                }
                else {
                    break;
                }
            }
            else {
                buffer += s[i];
            }
        }

        return buffer.length();
    }
};
