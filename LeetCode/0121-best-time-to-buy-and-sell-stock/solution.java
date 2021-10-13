class Solution {
    public int maxProfit(int[] prices) {
        int max = 0;

        int len = prices.length;

        if(len < 2) {
            return max;
        }

        int[] smallestPrices = new int[len];
        smallestPrices[0] = prices[0];

        for(int i=1;i<prices.length;i++) {
            smallestPrices[i] = Math.min(smallestPrices[i -1], prices[i]);
        }

        for(int i=prices.length-1;i>0;i--) {
            int guess = prices[i] - smallestPrices[i - 1];
            max = Math.max(guess, max);
        }

        return max;
    }
}
