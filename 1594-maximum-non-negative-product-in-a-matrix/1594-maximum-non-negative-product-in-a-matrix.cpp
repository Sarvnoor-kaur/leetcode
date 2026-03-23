class Solution {
public:
    int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>>mindp(m,vector<long long>(n,0));
        vector<vector<long long>>maxdp(m,vector<long long>(n,0));
        mindp[0][0]=maxdp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            mindp[i][0]=grid[i][0]*mindp[i-1][0];
            maxdp[i][0]=grid[i][0]*maxdp[i-1][0];       
        }
        for(int j=1;j<n;j++){
            mindp[0][j]=grid[0][j]*mindp[0][j-1];
            maxdp[0][j]=grid[0][j]*maxdp[0][j-1];
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // vector<int>temp;
                long long v1=maxdp[i-1][j]*grid[i][j];
                long long v2=maxdp[i][j-1]*grid[i][j];
                long long v3=mindp[i-1][j]*grid[i][j];
                long long v4=mindp[i][j-1]*grid[i][j];
                // temp.push_back(v1);
                // temp.push_back(v2);
                // temp.push_back(v3);
                // temp.push_back(v4);
                long long mini=min({v1,v2,v3,v4});
                long long maxi=max({v1,v2,v3,v4});

                // int mini=*min_element(temp.begin(),temp.end());
                // int maxi=*max_element(temp.begin(),temp.end());
                mindp[i][j]=mini;
                maxdp[i][j]=maxi;
            }
        }
        long long val=max(mindp[m-1][n-1],maxdp[m-1][n-1])%mod;
        return val>=0?val:-1;
    }
};