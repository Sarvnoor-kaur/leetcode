class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int curr=1;
        if(i-1>=0 && i-1<matrix.size() && matrix[i-1][j]>matrix[i][j]){
            curr=max(curr,1+dfs(i-1,j,matrix,dp));
        }
        if(i+1>=0 && i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            curr=max(curr,1+dfs(i+1,j,matrix,dp));
        }
        if(j-1>=0 && j-1<matrix[0].size() && matrix[i][j-1]>matrix[i][j]){
            curr=max(curr,1+dfs(i,j-1,matrix,dp));
        }
        if(j+1>=0 && j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            curr=max(curr,1+dfs(i,j+1,matrix,dp));
        }

        dp[i][j]=curr;
        return curr;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi=0;
        // vector<vector<int>>dp(matrix.size(),-1);
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                maxi=max(maxi,dfs(i,j,matrix,dp));
            }
        }
        return maxi;
    }
};