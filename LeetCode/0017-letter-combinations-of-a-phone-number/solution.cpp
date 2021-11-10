class Solution {
std::unordered_map<char, std::vector<char>> number_map = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};
    
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> results;

        for(char c : digits) {
            if(results.empty()) {
                for(char t : number_map[c]) {
                    results.emplace_back(1, t);
                }
            }
            else {
                std::vector<std::string> new_results;
                for(const auto& result : results) {
                    for(char t : number_map[c]) {
                        new_results.push_back(result + t);
                    }
                }
                results = new_results;
            }
        }

        return results;
    }
};
