class Solution {
public:
    bool isUgly(int n) {
		std::vector<int> prime_factors = {2, 3, 5}; 
        if(n == 0) {
            return false;
        }
        for(int p : prime_factors) {
            while(n % p == 0) {
                n /= p;
            }
        }
        return n == 1;
    }
};
