class Solution {
public:
    int value(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+value(nums,i+2,dp);
        int kip=value(nums,i+1,dp);
        return dp[i]=max(take,kip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return value(nums,0,dp);
    }
};