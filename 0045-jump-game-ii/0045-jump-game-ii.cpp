class Solution {
public:
    int jump(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1){
            return 0;
        }
        int re=1e9+7;
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int mxju=nums[i];
        for(int j=1;j<=mxju;j++){
            re=min(re,1+jump(i+j,nums,dp));
        }
        return dp[i]=re;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return jump(0,nums,dp);
    }
};