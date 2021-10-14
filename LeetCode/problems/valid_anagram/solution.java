class Solution {
    public boolean isAnagram(String s, String t) {
        char[] s_chars = s.toCharArray();
        char[] t_chars = t.toCharArray();
        int s_len = s_chars.length;

        if(s_len != t_chars.length) {
            return false;
        }

        Arrays.sort(s_chars);
        Arrays.sort(t_chars);

        for(int i=0;i<s_len;i++) {
            if(t_chars[i] != s_chars[i]) {
                return false;
            }
        }

        return true;
    }
}