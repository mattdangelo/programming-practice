#include <iostream>
#include <set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    if(s.length() < 2) {
        return s.length();
    }

    int max = 0;

    std::set<char> found;
    int l_ptr = 0;
    int r_ptr = 1;
    found.insert(s[0]);

    for(int i=1;i<s.length();i++) {
        max = std::max(r_ptr - l_ptr, max);
        if(found.find(s[i]) == found.end()) {
            // Haven't seen this char before
            r_ptr++;
            found.insert(s[i]);
        }
        else {
            while(s[l_ptr] != s[i]) {
                found.erase(s[l_ptr]);
                l_ptr++;
            }
            l_ptr++;
            r_ptr++;
        }
    }

    // Check after loop
    return std::max(r_ptr - l_ptr, max);
}

int main() {
    std::cout << (lengthOfLongestSubstring("abcabcbb") == 3) << std::endl;
    std::cout << (lengthOfLongestSubstring("bbbbb") == 1) << std::endl;
    std::cout << (lengthOfLongestSubstring("pwwkew") == 3) << std::endl;
    std::cout << (lengthOfLongestSubstring("") == 0) << std::endl;
    std::cout << (lengthOfLongestSubstring("dvdf") == 3) << std::endl;
    return 0;
}