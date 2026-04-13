class Solution {
public:
    int n;
    vector<int>dp;
    int getnextindex(vector<vector<int>>&arr,int start,int currjobend){
        int r=n-1;
        int res=n;
        while(start<=r){
            int mid=start+(r-start)/2;
            if(arr[mid][0]>=currjobend){
                res=mid;
                r=mid-1;
            }else{
                start=mid+1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>>&arr,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int nextin=getnextindex(arr,i+1,arr[i][1]);
        int take=arr[i][2]+solve(arr,nextin);
        int nottake=solve(arr,i+1);
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>>arr(n,vector<int>(3,0));
        dp=vector<int>(n,-1);
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }
        sort(arr.begin(),arr.end());
        return solve(arr,0);

        
    }
};