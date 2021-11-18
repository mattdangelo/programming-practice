class Solution {
public:
    string reverseString(string s) {
        string buffer = s;
        int left = 0;
        int right = buffer.length() - 1;
        while(left < right) {
            char tmp = buffer[left];
            buffer[left] = buffer[right];
            buffer[right] = tmp;
            left++;
            right--;
       }
        return buffer;
    }
    string reverseWords(string s) {
        string result;
        
        string buffer;
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                // reverse buffer and add to result
                result += reverseString(buffer) + " ";
                buffer = "";
            }
            else {
                buffer = buffer + s[i];
            }
        }
        result += reverseString(buffer);
        
        return result;
    }
};