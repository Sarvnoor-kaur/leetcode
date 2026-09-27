class Solution {
    public String removeDuplicates(String s) {

        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {

            if (st.empty()) {
                st.push(s.charAt(i));
            } 
            else {
                if (st.peek() == s.charAt(i)) {
                    st.pop();
                } 
                else {
                    st.push(s.charAt(i));
                }
            }
        }

        String res = "";

        while (!st.empty()) {
            res += st.pop();
        }

        return new StringBuilder(res).reverse().toString();
    }
}