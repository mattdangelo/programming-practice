class Solution {
    std::unordered_map<char, int> count_map;
public:
    string frequencySort(string s) {
        // Step 1: Count occurrences in a map
        for(char c : s) {
            if(count_map.count(c)) {
                count_map[c]++;
            }
            else {
                count_map[c] = 1;
            }
        }

        // Step 2: Copy occurrences to a vector and sort by count
        std::vector<std::pair<char, int>> count_array;
        count_array.reserve(count_map.size());
        for(std::pair<char, int> p : count_map) {
            count_array.push_back(p);
        }

        std::sort(count_array.begin(), count_array.end(), [](const std::pair<char, int>& lhs, const std::pair<char, int>& rhs) {
            return lhs.second > rhs.second;
        });

        // Step 3: Reconstruct string
        std::string ret;
        ret.resize(s.length());
        int ptr = 0;
        for(std::pair<char, int> p : count_array) {
            for(int i=0;i<p.second;i++) {
                ret[ptr++] = p.first;
            }
        }

        return ret;
    }
};
