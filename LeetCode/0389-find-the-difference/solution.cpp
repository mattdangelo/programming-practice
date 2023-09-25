class Solution {
public:
    char findTheDifference(string s, string t) {
        std::unordered_map<char, int> count;
        for(char c : t) {
            if(count.count(c)) {
                count[c]++;
            }
            else {
                count[c] = 1;
            }
        }

        for(char c : s) {
            count[c]--;
            if(count[c] == 0) {
                count.erase(c);
            }
        }

        for(std::pair<char, int> p : count) {
            return p.first;
        }

        return ' ';
    }
};
