class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() > haystack.length()) {
            return -1;
        }
        
        int left = 0;
        int right = needle.size();
        
        while(right <= haystack.size()) {
            if(haystack.substr(left, right - left) == needle) {
                return left;
            }
            left++;
            right++;
        }
        
        return -1;
    }
};