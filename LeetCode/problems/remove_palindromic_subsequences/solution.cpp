class Solution {
public:
    int removePalindromeSub(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while(left < right) {
            if(s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return 2;
            }
        }
        
        return 1;
    }
};