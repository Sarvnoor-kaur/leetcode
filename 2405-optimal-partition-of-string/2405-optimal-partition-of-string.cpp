class Solution {
public:
    int partitionString(string s) {

        int l=0;
        // int maxlen=0;
        int c=1;
        unordered_set<char>st;
        for(int i=0;i<s.size();i++){
            while(st.find(s[i])!=st.end()){
                c++;
                // st.erase(s[l]);
                st.clear();
            }
            st.insert(s[i]);
        }
        return c;
        
    }
};