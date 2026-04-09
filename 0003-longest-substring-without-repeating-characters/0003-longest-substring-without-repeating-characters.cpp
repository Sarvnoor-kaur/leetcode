class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<bool> count(256,0);
        // int first=0,second=0,len=0;
        // while(second<s.size()){
        //     while(count[s[second]]){
        //         count[s[first]]=0;
        //         first++;
        //     }
        //     count[s[second]] = 1;
        //     len=max(len,second-first+1);
        //     second++;
        // }
        // return len;






















        unordered_set<char>st;
        // int start=0,right=s.size();
        int maxlen=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
        
    }
};