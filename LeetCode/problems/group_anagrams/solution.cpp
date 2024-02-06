class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for(string &s : strs) {
            std::string sorted = s;
            std::sort(sorted.begin(), sorted.end());
            if(groups.count(sorted)) {
                groups[sorted].push_back(s);
            }
            else {
                std::vector<std::string> value;
                value.push_back(s);
                groups[sorted] = value;
            }
        }

        std::vector<std::vector<std::string>> results;
        results.reserve(groups.size());
        for(auto &kv : groups) {
            results.push_back(std::move(kv.second));
        }

        return results;
    }
};