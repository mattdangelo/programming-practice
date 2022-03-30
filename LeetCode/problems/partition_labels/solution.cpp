class Solution {
public:
    vector<int> partitionLabels(string s) {
        std::map<char, int> last_occ;
        
        for(int i=0;i<s.length();i++) {
            if(last_occ.find(s[i]) == last_occ.end()) {
                last_occ[s[i]] = i;
            }
            else {
                last_occ[s[i]] = i;
            }
        }

        std::vector<int> ret;
        int left = 0;
        int right = last_occ[s[left]];
        int start = -1;

        for(int i = 0; i < s.size(); i++){
            right = std::max(right, last_occ[s[i]]);
            if(i == right) {
                ret.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return ret;
    }
};