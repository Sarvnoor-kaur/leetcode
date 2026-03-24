class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>flat;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                flat.push_back(grid[i][j]);
            }
        }
        int total=flat.size();
        vector<long long>pre(total,1);
        vector<long long>suf(total,1);
        for(int i=1;i<total;i++){
            pre[i]=(pre[i-1]*flat[i-1])%12345;
        }
        for(int i=total-2;i>=0;i--){
            suf[i]=(suf[i+1]*flat[i+1])%12345;
        }
        vector<int>ans(total);
        for(int i=0;i<total;i++){
            ans[i]=(1LL * pre[i]*suf[i])%12345;
        }
        vector<vector<int>>res(m,vector<int>(n));
        int index=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j]=ans[index++];
            }
        }
        return res;

    }
};