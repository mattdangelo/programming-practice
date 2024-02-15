class Solution {
    bool isPalindromic(const std::string& s) {
        int left = 0;
        int right = s.length() - 1;
        while(left <= right) {
            if(s[left] != s[right]) {
                return false;
            }
            else {
                left++;
                right--;
            }
        }

        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(std::string s : words) {
            if(isPalindromic(s)) {
                return s;
            }
        }

        return "";
    }
};
