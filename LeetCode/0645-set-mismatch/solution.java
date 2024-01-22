class Solution {
    public int[] findErrorNums(int[] nums) {
        Arrays.sort(nums);
        int dup = -1;
        int actualSum = nums[nums.length - 1];
        int correctSum = nums.length;
        for(int i=0;i<nums.length - 1;i++) {
            actualSum += nums[i];
            correctSum += i + 1;
            if(nums[i] == nums[i + 1]) {
                dup = nums[i];
            }
        }

        int[] res = { dup, correctSum - (actualSum - dup) };
        return res;
    }
}
