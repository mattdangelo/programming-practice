class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int current_consec = 1;
        for(int i=0;i<flowerbed.size();i++) {
            if(!flowerbed[i]) {
                current_consec++;
            }
            else {
                n -= (current_consec - 1) / 2;
                if(n <= 0) {
                   return true;
                }
                current_consec = 0;
            }
        }
        
        n -= current_consec / 2;
        return n <= 0;
    }
};