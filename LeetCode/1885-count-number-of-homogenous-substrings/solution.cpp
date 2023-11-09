class Solution {
public:
    int countHomogenous(string s) {
        int global_count = 0;
        int local_count = 0;
        char current = '_';
        for(int i=0;i<s.length();i++) {
            if(s[i] == current) {
                local_count++;
            }
            else {
                local_count = 1;
            }
            current = s[i];
            global_count = (local_count + global_count) % 1000000007;
        }

        return global_count;
    }
};
