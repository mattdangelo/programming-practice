class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length];
        int count = 0;
        for (int value : nums1) {
            for (int j = 0; j < nums2.length; j++) {
                if (value == nums2[j]) {
                    int old_count = count;
                    for (int k = j; k < nums2.length; k++) {
                        if (nums2[k] > nums2[j]) {
                            result[count] = nums2[k];
                            count++;
                            break;
                        }
                    }
                    if (old_count == count) {
                        result[count] = -1;
                        count++;
                    }
                }
            }
        }

        return result;
    }
}