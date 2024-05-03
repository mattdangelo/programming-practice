class Solution {
    // Convert version string to an array of integers
    std::vector<int> getTokens(std::string s) {
        std::vector<int> ret;
        std::string buffer;
        for(char c : s) {
            if(c == '.') {
                ret.push_back(std::stoi(buffer));
                buffer = "";
            }
            else {
                buffer += c;
            }
        }

        ret.push_back(std::stoi(buffer));

        return ret;
    }

public:
    int compareVersion(string version1, string version2) {
        // Tokenize the 2 versions
        std::vector<int> v1_values = getTokens(version1);
        std::vector<int> v2_values = getTokens(version2);

        int longest = std::max(v1_values.size(), v2_values.size());
        
        // Compare tokens 1 by 1 (substituting 0 where we don't have enough tokens)
        for(int i=0;i<longest;i++) {
            int v1_value = v1_values.size() > i ? v1_values[i] : 0;
            int v2_value = v2_values.size() > i ? v2_values[i] : 0;

            if(v1_value < v2_value) {
                return -1;
            }
            else if(v1_value > v2_value) {
                return 1;
            }
        }

        return 0;
    }
};
