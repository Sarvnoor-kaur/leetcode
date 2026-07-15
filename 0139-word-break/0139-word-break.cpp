class Solution {
public:

    bool calback(int in,string s,unordered_set<string>&dict,vector<int>&dp){
        if(s.empty()) return true;
        // if(in==s.size()){
        //     return true;
        // }
        if(dp[in]!=-1){
            return dp[in];
        }
        for(int i=1;i<=s.size();i++){
            string pre=s.substr(0,i);
            string suf=s.substr(i);
            if(dict.count(pre) && calback(in+i,suf,dict,dp)){
                return dp[in]=true;
            }
        }
        return dp[in]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return calback(0,s,dict,dp);
        
    }
};