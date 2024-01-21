class Solution {
    private int[][] mat;
    private int[][] cache;
    private int n;

    private int recMinFallingPathSum(int row, int col) {
        // Base case - we're at the bottom, just return what the current sum is
        if(row >= n) {
            return 0;
        }

        if(cache[row][col] != Integer.MAX_VALUE) {
            return cache[row][col];
        }

        int midPath = recMinFallingPathSum(row + 1, col);

        int leftPath = Integer.MAX_VALUE;
        if(col > 0) {
            leftPath = recMinFallingPathSum(row + 1, col - 1);
        }

        int rightPath = Integer.MAX_VALUE;
        if(col < n - 1) {
            rightPath = recMinFallingPathSum(row + 1, col + 1);
        }

        cache[row][col] = mat[row][col] + Math.min(Math.min(leftPath, rightPath), midPath);
        return cache[row][col];
    }

    public int minFallingPathSum(int[][] matrix) {
        mat = matrix;
        n = mat.length;

        // Initialize cache
        cache = new int[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cache[i][j] = Integer.MAX_VALUE;
            }
        }

        // Call recusrive recMinFallingPathSum for each possible starting point
        int best = Integer.MAX_VALUE;
        for(int i=0;i<n;i++) {
            int res = recMinFallingPathSum(0, i);
            if(res < best) {
                best = res;
            }
        }

        return best;
    }
}
