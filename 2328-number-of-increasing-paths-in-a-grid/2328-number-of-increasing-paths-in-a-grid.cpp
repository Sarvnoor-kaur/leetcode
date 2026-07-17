class Solution {
public:
    int mod=1e9+7;
    int dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i>=matrix.size() || j>=matrix[0].size()|| i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int c=1;
        if(i-1>=0 && i-1<matrix.size() && matrix[i-1][j]>matrix[i][j]){
            c=(c+dfs(i-1,j,matrix,dp))%mod;
        }
        if(i+1>=0 && i+1<matrix.size() && matrix[i+1][j]>matrix[i][j]){
            c=(c+dfs(i+1,j,matrix,dp))%mod;
        }
        if( j-1>=0 && j-1<matrix[0].size() && matrix[i][j-1]>matrix[i][j]){
            c=(c+dfs(i,j-1,matrix,dp))%mod;
        }
        if( j+1>=0 && j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j]){
            c=(c+dfs(i,j+1,matrix,dp))%mod;
        }
        dp[i][j]=c;
        return c;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        long long c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                c=(c+dfs(i,j,grid,dp))%mod;
            }
        }
        return c;
    }
};