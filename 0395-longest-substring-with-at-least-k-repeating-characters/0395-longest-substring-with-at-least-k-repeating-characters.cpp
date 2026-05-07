class Solution {
public:
    // bool satisfy(string temp,int k){
    //     unordered_map<char,int>mp;
    //     for(int i=0;i<temp.size();i++){
    //         mp[temp[i]]++;
    //     }

    //     for(auto &m:mp){
    //         if(m.second<k){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    int longestSubstring(string s, int k) {
        // int maxi=0;
        // for(int i=0;i<s.size();i++){
        //     for(int j=i;j<s.size();j++){
        //         if(satisfy(s.substr(i,j-i+1),k)){
        //             int len=j-i+1;
        //             maxi=max(maxi,len);
        //         }
        //     }
        // }
        // return maxi;
        // int maxi=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]<k){
                int left=longestSubstring(s.substr(0,i),k);
                int right=longestSubstring(s.substr(i+1),k);
                return max(left,right);
            }
            
        }
        return s.size();
    }
};