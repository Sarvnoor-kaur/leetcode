class Solution {
    public void reverseString(char[] s) {
        // StringBuilder sb=new StringBuilder(new String(s));
        // sb.reverse().getChars(0, s.length, s, 0);


        Stack<Character>st=new Stack<>();

        for(int i=0;i<s.length;i++){
            st.push(s[i]);
        }
        int i=0;
        // StringBuilder se=new StringBuilder();
        while(!st.empty()){

            char t=st.peek();
            // se.append(t);
            s[i]=t;
            st.pop();
            i++;
        }

        
    }
}