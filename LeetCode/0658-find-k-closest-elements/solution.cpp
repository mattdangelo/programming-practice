class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::sort(arr.begin(), arr.end(), [&x](const int& a, const int& b) {
            int abs_a = abs(a - x);
            int abs_b = abs(b - x);
            
            if(abs_a == abs_b) {
                return a < b;
            }
            else {
                return abs_a < abs_b;
            }
        });

        arr.resize(k);
        std::sort(arr.begin(), arr.end());
        return arr;
    }
};
