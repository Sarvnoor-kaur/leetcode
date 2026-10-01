class Solution {
    public boolean isValid(String s) {

        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            // Opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {

                // No opening bracket available
                if (st.empty()) {
                    return false;
                }

                // Check matching bracket
                if ((ch == ')' && st.peek() != '(') ||
                    (ch == '}' && st.peek() != '{') ||
                    (ch == ']' && st.peek() != '[')) {
                    
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
}