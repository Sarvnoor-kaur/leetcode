class Solution {
public:
    bool jump(vector<int>&num,int i,vector<int>&dp){
        if(i>=num.size()-1){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxj=num[i];
        for(int j=1;j<=maxj;j++){
            if(jump(num,i+j,dp)){
                dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
    bool canJump(vector<int>& num) {
        int n=num.size();
        vector<int>dp(n,-1);
        return jump(num,0,dp);
    }
};