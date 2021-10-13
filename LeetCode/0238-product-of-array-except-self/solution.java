class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] leftPartialProducts = new int[len];
        int[] rightPartialProducts = new int[len];
        leftPartialProducts[0] = nums[0];
        rightPartialProducts[0] = nums[len - 1];
        for(int i=1;i<len;i++) {
            leftPartialProducts[i] = leftPartialProducts[i - 1] * nums[i];
            rightPartialProducts[i] = rightPartialProducts[i - 1] * nums[len - i - 1];
        }

        int[] result = new int[len];
        for(int k=0;k<len;k++) {
            if(k == 0) {
                result[k] = rightPartialProducts[len - 2];
            }
            else if(k == len - 1) {
                result[k] = leftPartialProducts[len - 2];
            }
            else {
                result[k] = leftPartialProducts[k - 1] * rightPartialProducts[len - k - 2];
            }
        }

        return result;
    }
}
