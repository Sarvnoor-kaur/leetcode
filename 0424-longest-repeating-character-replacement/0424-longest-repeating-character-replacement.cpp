class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0;
        int maxi=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            maxi=max(maxi,mp[s[r]]);
            while((r-l+1)-maxi>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};