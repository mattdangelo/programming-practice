package com.leetcode;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
	    Solution s = new Solution();
        int[] values = {2,0,2,1,1,0};
        s.sortColors(values);
        System.out.println(Arrays.toString(values));
    }
}
