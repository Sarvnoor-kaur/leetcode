class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=s.size();
        unordered_set<char>st;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                int len=i-l+1;
                maxi=max(maxi,len);
            }else{
                while(st.find(s[i])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[i]);
                int len=i-l+1;
                maxi=max(maxi,len);

            }
            // while(st.find(s[i])!=st.end()){
            //     st.erase(s[l]);
            //     l++;
            // }
            // st.insert(s[i]);
            // int len=i-l+1;
            // maxi=max(maxi,len);

        }
        return maxi;
    }
};