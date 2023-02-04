class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            false;
        }

        std::unordered_map<char, int> s1_chars;
        for (char c : s1) {
            if (s1_chars.count(c) == 0) {
                s1_chars[c] = 1;
            }
            else {
                s1_chars[c]++;
            }
        }

        // Sliding window
        int left = 0;
        int right = s1.length();

        while (right <= s2.length()) {
            auto s1_chars_cpy = s1_chars;
            bool skip_check = false;
            for (int i = left; i < right; i++) {
                char to_rem = s2[i];
                if (s1_chars_cpy.count(to_rem) == 0) {
                    skip_check = true;
                    break;
                }
                else if (s1_chars_cpy.count(to_rem)) {
                    // Count is at least 1
                    if (s1_chars_cpy[to_rem] == 1) {
                        s1_chars_cpy.erase(to_rem);
                    }
                    else {
                        s1_chars_cpy[to_rem]--;
                    }
                }
            }

            if (!skip_check && s1_chars_cpy.empty()) {
                return true;
            }

            left++;
            right++;
        }

        return false;
    }
};