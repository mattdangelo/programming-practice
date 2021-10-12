class Solution {
    public int lengthOfLongestSubstring(String s) {
        StringBuilder test = new StringBuilder();

        int max = -1;

        if(s.length() < 2) {
            return s.length();
        }

        for(char c : s.toCharArray()) {
            String current = String.valueOf(c);

            if(test.toString().contains(current)) {
                test = new StringBuilder(test.substring(test.indexOf(current) + 1));
            }
            
            test.append(c);

            if(test.length() > max) {
                max = test.length();
            }
        }

        return max;
    }
}
