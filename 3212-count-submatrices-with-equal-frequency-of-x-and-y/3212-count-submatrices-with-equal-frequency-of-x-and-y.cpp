class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>>mat(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>xc(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='X'){
                    mat[i][j]=1;
                }else if(grid[i][j]=='Y'){
                    mat[i][j]=-1;
                }
            }
        }
        dp[0][0]=mat[0][0];
        xc[0][0]=(grid[0][0]=='X');
        for(int i=1;i<mat.size();i++){
            dp[i][0]=dp[i-1][0]+mat[i][0];
            xc[i][0]=xc[i-1][0]+(grid[i][0]=='X');
        }
        for(int j=1;j<mat[0].size();j++){
            dp[0][j]=dp[0][j-1]+mat[0][j];
            xc[0][j]=xc[0][j-1]+(grid[0][j]=='X');
        }
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i][j]-dp[i-1][j-1];
                xc[i][j]=xc[i-1][j]+xc[i][j-1]+(grid[i][j]=='X')-xc[i-1][j-1];
                
            }
        }
        int c=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(dp[i][j]==0 && xc[i][j]>0){
                    c++;
                }
            }
        }
        return c;

    }
};