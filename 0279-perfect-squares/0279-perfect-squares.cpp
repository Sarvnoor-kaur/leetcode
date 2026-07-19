class Solution {
public:
    int perfect(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int re=INT_MAX;
        for(int i=1;i*i<=n;i++){
            re=min(re,1+perfect(n-i*i,dp));
        }
        return dp[n]=re;

    }
    int numSquares(int n) {
       vector<int>dp(n+1,-1);
       return perfect(n,dp);
    }
};