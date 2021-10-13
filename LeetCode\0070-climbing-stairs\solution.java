class Solution {
    static ArrayList<Integer> numOfWays = new ArrayList<>(Collections.nCopies(45, -1)) {
        {
            set(0, 1);
            set(1, 2);
        }
    };

    public static int climbStairs(int n) {
        if(numOfWays.get(n - 1) != -1) {
            return numOfWays.get(n - 1);
        }
        else {
            int to_memo = climbStairs(n - 1) + climbStairs(n - 2);
            numOfWays.set(n - 1, to_memo);
            return to_memo;
        }
    }
}
