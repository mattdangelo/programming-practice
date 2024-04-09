class Solution {
public:
    bool checkInclusion(string p, string s) {
        if (p.length() > s.length()) {
            return false;
        }

        // Sliding window
        std::vector<int> p_values(26, 0);
        std::vector<int> win_values(26, 0);

        for(int i=0;i<p.length();i++) {
            p_values[p[i] - 'a']++;
            win_values[s[i] - 'a']++;
        }

        if(p_values == win_values) {
            return true;
        }

        for(int left = p.length(); left < s.length(); left++){
            win_values[s[left - p.length()] - 'a']--;
            win_values[s[left] - 'a']++;

            if(p_values == win_values) {
                return true;
            }
        }

        return false;
    }
};