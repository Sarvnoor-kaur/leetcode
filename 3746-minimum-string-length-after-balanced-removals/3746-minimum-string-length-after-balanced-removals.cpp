class Solution {
public:
    int minLengthAfterRemovals(string s) {
        // counta=0;
        // countb=0;
        // for(int i=0;i<s.size();i++){
            
        // }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                if(!st.empty() && st.top()=='a'){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};