/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int ceil = n;
        int floor = 0;

        while(ceil != floor) {
            int g = (int)(((long)ceil + (long)floor) / 2L);
            int i = guess(g);
            if(i == -1) {
                ceil = g;
            }
            else if(i == 1) {
                floor = g + 1;
            }
            else {
                return g;
            }
        }
        
        return ceil;
    }
}