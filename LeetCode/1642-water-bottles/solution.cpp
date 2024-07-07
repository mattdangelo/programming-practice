class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Take all of the bottles we have initially
        int total = numBottles;
        int swapped = 0;
        while(numBottles >= numExchange) {
            // We can swap the floor of the division of the number we have
            // and the amount we're allowed to swap
            swapped = numBottles / numExchange;

            // Add these to the total
            total += swapped;

            // The remaining bottles is however many bottles we swapped + the remainder
            numBottles = swapped + (numBottles % numExchange);
        }

        return total;
    }
};
