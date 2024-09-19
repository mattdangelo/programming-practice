class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        std::unordered_map<std::string, int> s1_count;
        std::unordered_map<std::string, int> s2_count;

        // Count the occurences in each string
        std::vector<std::string> s1_tokens = tokenize(s1);
        for(std::string s : s1_tokens) {
            s1_count[s]++;
        }

        std::vector<std::string> s2_tokens = tokenize(s2);
        for(std::string s : s2_tokens) {
            s2_count[s]++;
        }

        // Find any words that exist in s1 exactly once, but not in s2
        std::vector<std::string> result;
        for(std::string s : s1_tokens) {
            if(s2_count[s] == 0 && s1_count[s] == 1) {
                result.push_back(s);
            }
        }

        // Do the inverse for s2
        for(std::string s : s2_tokens) {
            if(s2_count[s] == 1 && s1_count[s] == 0) {
                result.push_back(s);
            }
        }

        return result;
    }
private:
    // Take a string and split it into tokens seperated by space
    std::vector<std::string> tokenize(std::string s) {
        std::vector<string> result;
        std::string buffer = "";
        for(char c : s) {
            if(c != ' ') {
                buffer += c;
            }
            else {
                result.push_back(buffer);
                buffer = "";
            }
        }
        result.push_back(buffer);

        return result;
    }
};
