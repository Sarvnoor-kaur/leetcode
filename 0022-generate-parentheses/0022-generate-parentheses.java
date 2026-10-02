class Solution {

    void gen(int n, ArrayList<String> v, StringBuilder re, int o, int c) {

        // Base case
        if (re.length() == 2 * n) {
            v.add(re.toString());
            return;
        }

        // Add '(' if opening brackets are still available
        if (o < n) {
            re.append('(');
            gen(n, v, re, o + 1, c);
            re.deleteCharAt(re.length() - 1);
        }

        // Add ')' only when there is an unmatched '('
        if (c < o) {
            re.append(')');
            gen(n, v, re, o, c + 1);
            re.deleteCharAt(re.length() - 1);
        }
    }

    public List<String> generateParenthesis(int n) {

        ArrayList<String> v = new ArrayList<>();
        StringBuilder re = new StringBuilder();

        gen(n, v, re, 0, 0);

        return v;
    }
}