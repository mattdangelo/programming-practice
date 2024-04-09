class Solution {
    private static final int SKIPPED = 0;
    private static final int TOOK = 1;

    private int[][] cache;

    private int recRob(int[] nums, int curPos, int curSum, int tookPrev) {

        // Base case: We've finished the array, so just return the sum we have
        if(curPos >= nums.length) {
            return curSum;
        }

        // If we've been here before with a higher sum, just return now. There's 
        // no way we can do any better
        if((tookPrev == SKIPPED && cache[curPos][TOOK]    >= curSum) ||
           (tookPrev == TOOK    && cache[curPos][SKIPPED] >= curSum)) {
            return curSum;
        }

        // If we've done better than the cache, update it
        int take = recRob(nums, curPos + 2, curSum + nums[curPos], TOOK);
        if(curSum + nums[curPos] > (cache[curPos + 2][TOOK])) {
            cache[curPos + 2][TOOK] = curSum + nums[curPos];
        }

        int skip = recRob(nums, curPos + 1, curSum, SKIPPED);
        if(curSum > cache[curPos + 1][SKIPPED]) {
            cache[curPos + 1][SKIPPED] = curSum;
        }

        // Return whatever path led to a higher sum
        int best = Math.max(take, skip);

        return best;
    }

    public int rob(int[] nums) {
        // Initalize cache with -1
        cache = new int[nums.length + 2][2];
        for(int i=0;i<nums.length + 2;i++) {
            cache[i][SKIPPED] = -1;
            cache[i][TOOK] = -1;
        }
  
        return recRob(nums, 0, 0, SKIPPED);
    }
}