class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        std::vector<std::string> res; 
        res.reserve(s.length() / k);
        std::string buffer;
        for(int i=0;i<s.length();i+=k) {
            buffer = s.substr(i, k);
            while(buffer.length() < k) {
                buffer += fill;
            }
            res.push_back(buffer);
        }

        return res;
    }
};
