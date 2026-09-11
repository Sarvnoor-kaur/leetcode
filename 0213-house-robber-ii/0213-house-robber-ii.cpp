class Solution {
public:
    int value(vector<int>&nums,int i,vector<int>&dp,int n){
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+value(nums,i+2,dp,n);
        int kip=value(nums,i+1,dp,n);
        return dp[i]=max(take,kip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int take=value(nums,0,dp1,n-2);
        int kip=value(nums,1,dp2,n-1);
        return max(take,kip);
    }
};