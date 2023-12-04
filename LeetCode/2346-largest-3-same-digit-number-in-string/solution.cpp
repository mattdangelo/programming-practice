class Solution {
public:
    string largestGoodInteger(string num) {
        std::string best = "";
    
        for(int i=0;i<num.size() - 2;i++) {
            if(num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                if((best.length() == 0) || num[i] > best[0]) {
                    best = num.substr(i, 3);
                }
            }
        }

        return best;
    }
};
