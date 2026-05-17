class Solution {
public:
    bool solve(vector<int>&arr,int start,vector<int>&dp,int n){
        if(start>=n || start<0){
            return false;
        }
        if(arr[start]==0){
            return true;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        dp[start]=0;
        if(solve(arr,start+arr[start],dp,n)){
            dp[start]=1;
            return true;
        }
        if(solve(arr,start-arr[start],dp,n)){
            dp[start]=1;
            return true;
        }
        
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        
        vector<int>dp(n,-1);
        return solve(arr,start,dp,n);        
    }
};