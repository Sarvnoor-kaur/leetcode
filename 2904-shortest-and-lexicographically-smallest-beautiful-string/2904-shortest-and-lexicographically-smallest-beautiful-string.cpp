class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char,int>mp;
        vector<string>le;
        int t=-1;
        int mini=INT_MAX;
        int l=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp['1']>k){
                mp[s[l]]--;
                l++;
            }
            if(mp['1']==k){
                while (s[l]=='0') {
                    mp[s[l]]--;
                    l++;
                }

                int len=i-l+1;
                if(len<mini){
                    mini=min(mini,len);
                    t=l;
                }else if (len == mini) {
                    string curr = s.substr(l, mini);
                    string prev = s.substr(t, mini);

                    if (curr<prev) {
                        t=l;
                    }
                }
            }
        }
        if(t==-1){
            return "";
        }
        return s.substr(t,mini);
    }
};