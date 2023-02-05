class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.length() > s.length()) {
            return res;
        }

        // Sliding window
        std::vector<int> p_values(26, 0);
        std::vector<int> win_values(26, 0);

        for(int i=0;i<p.length();i++) {
            p_values[p[i] - 'a']++;
            win_values[s[i] - 'a']++;
        }

        if(p_values == win_values) {
            res.push_back(0);
        }

        for(int left = p.length(); left < s.length(); left++){
            win_values[s[left - p.length()] - 'a']--;
            win_values[s[left] - 'a']++;

            if(p_values == win_values) {
                res.push_back(left - p.length() + 1);
            }
        }

        return res;
    }
};