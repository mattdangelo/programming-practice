class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // Pass 1: Set the location of the first and last occurence of each unique character in the string - O(n)
        std::unordered_map<char, std::pair<int, int>> first_last;
        for(int i=0;i<s.length();i++) {
            if(first_last.count(s[i])) {
                first_last[s[i]].second = i;
            }
            else {
                first_last[s[i]] = {i, -1};
            }
        }

        // Pass 2: Count the number of unique characters between the first and last occurence of each character - O(n * 26)
        int count = 0;

        for(auto kv : first_last) {
            std::pair<int, int> p = kv.second;
            if(p.second == -1) {
                // There was only 1 occurence of the character in the string, skip it
                continue;
            }
            else {
                // Count the number of unique characters between left and right
                int left = p.first;
                int right = p.second;

                std::unordered_set<char> seen;
                for(int i=left + 1;i<=right-1;i++) {
                    if(!seen.count(s[i])) {
                        seen.insert(s[i]);
                    }
                }

                count += seen.size();
            }
        }

        return count;
    }
};