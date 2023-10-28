class Solution {
public:
    string longestPalindrome(string s) {
        string best = s.substr(0, 1);

        for(int i=0;i<s.length();i++) {
                        // Try odd length palindromes here
            int left = i;
            int right = i;
            while(s[left] == s[right]) {
                if(best.length() < (right - left + 1)) {
                    best = s.substr(left, right - left + 1);
                }

                left --;
                right++;
                if(left < 0 || right > s.length() - 1) {
                    break;
                }
            }

            // Try even length palindromes here
            left = i;
            right = i + 1;
            while((right < s.length()) && s[left] == s[right]) {
                if(best.length() < (right - left + 1)) {
                    best = s.substr(left, right - left + 1);
                }

                left --;
                right++;
                if(left < 0 || right > s.length() - 1) {
                    break;
                }
            }
        }

        return best;
    }
};
