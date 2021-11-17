class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::vector<int> low(prices.size()+1);
        std::vector<int> high(prices.size()+1);
        low[0] = 1000000;
        high[prices.size()] = -1;
        
        for(int i=1;i<prices.size() + 1;i++) {
            low[i] = min(low[i-1], prices[i-1]);
        }
        
        for(int i=prices.size();i>0;i--) {
            high[i - 1] = max(high[i], prices[i - 1]);
        }
        
        int best = 0;
        for(int i=0;i<low.size();i++) {
            int sum = high[i] - low[i];
            if(sum > best) {
                best = sum;
            }
        }
        
        return best;
    }
};