class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            false;
        }

        // Sliding window
        int left = 0;
        int right = s1.length();
        sort(s1.begin(), s1.end());

        while (right <= s2.length()) {
            string s2_substr = s2.substr(left, s1.length());
            sort(s2_substr.begin(), s2_substr.end());
            if(s2_substr == s1) {
                return true;
            }

            left++;
            right++;
        }

        return false;
    }
};