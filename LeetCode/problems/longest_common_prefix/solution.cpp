class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ptr = 0;
        int min = strs[0].length();
       
        // Early exit
        if(strs.size() == 1) {
            return strs[0];
        }
        
        for(int i=1;i<strs.size();i++) {
            int len = strs.at(i).length();
            if(len < min) {
                min = len;
            }
        }
        
        bool all_match = true;

        while(all_match) {
            if(ptr == min) {
                return strs[0].substr(0,ptr);
            }
                
            for(int i=1;i<strs.size();i++) {
                if(strs.at(i)[ptr] != strs[0][ptr]) {
                    all_match = false;
                    break;
                }
            }
        
            if(all_match) {
                ptr++;
            }
        }

        return strs[0].substr(0,ptr);
    }
};