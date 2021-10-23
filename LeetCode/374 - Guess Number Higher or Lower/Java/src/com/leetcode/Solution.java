package com.leetcode;

class Solution {
    int number;

    public Solution(int number) {
        this.number = number;
    }

    private int guess(int g) {
        if(number < g) {
            return -1;
        }
        else if(number > g) {
            return 1;
        }

        return 0;
    }

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
