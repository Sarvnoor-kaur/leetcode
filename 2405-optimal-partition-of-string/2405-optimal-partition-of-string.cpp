class Solution {
public:
    int partitionString(string t) {
        int c=1;
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++){
            mp[t[i]]++;
            if(mp[t[i]]>1){
                c++;
                mp.clear();
                mp[t[i]]++;
                
            }
        }
        return c;
    }
};