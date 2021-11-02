#include <iostream>
#include <unordered_map>
#include <algorithm>

bool isAnagram(std::string s, std::string t) {
    if(s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> s_count;

    for(char c : s) {
        if(s_count.count(c)) {
            s_count[c] = s_count[c] + 1;
        }
        else{
            s_count[c] = 1;
        }
    }

    for(char c : t) {
        if(s_count.count(c)) {
            s_count[c] = s_count[c] - 1;
        }
        else{
            return false;
        }
    }

    return std::all_of(s_count.begin(), s_count.end(), [](const auto& p){ return p.second == 0; });
}

int main() {
    std::cout << isAnagram("anagram", "nagaram") << std::endl;
    return 0;
}