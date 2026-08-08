class Solution {
public:
     int count(int i,int j,string v, string t,vector<vector<int>>&dp){
        if(j==t.size())return 1;
        if(i==v.size())return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long an=0;
        if(v[i]==t[j]){
            an=count(i+1,j+1,v,t,dp)+count(i+1,j,v,t,dp);
        }else{
            an=count(i+1,j,v,t,dp);
        }
        return dp[i][j]=(int)an;
    }
    int numDistinct(string v, string t) {
        int n=v.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return count(0,0,v,t,dp);
    }
};