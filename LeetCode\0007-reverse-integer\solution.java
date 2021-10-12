class Solution {
    public int reverse(int x) {
        boolean negative = x < 0;
        String string_rep = String.valueOf(x);
        if(negative) {
            string_rep = string_rep.substring(1);
        }

        string_rep = new StringBuilder(string_rep).reverse().toString();

        try {
            return Integer.parseInt(negative ? "-" + string_rep :string_rep);
        }
        catch (NumberFormatException e) {
            return 0;
        }
    }
}
