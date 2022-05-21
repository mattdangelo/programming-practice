class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int max = amount + 1;
        std::vector<int> memo(amount + 1, max);
        memo[0] = 0;

        for(int i=1;i<=amount;i++) {
            for(int coin : coins) {
                if(coin <= i) {
                    memo[i] = min(memo[i], memo[i - coin] + 1);
                }               
            }
        }
        
        return memo[amount] > amount ? -1 : memo[amount];
    }
};