class Solution {
    const std::string numbers = "123456789";
public:
    vector<int> sequentialDigits(int low, int high) {
        std::vector<int> res;
        for(int l=0;l<9;l++) {
            for(int r=l + 1;r<10;r++) {
                int new_num = stoi(numbers.substr(l, r - l));
                if(new_num >= low && new_num <= high) {
                    res.push_back(new_num);
                }
            }
        }

        std::sort(res.begin(), res.end());
        return res;
    }
};