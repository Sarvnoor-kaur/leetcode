class Solution {
public:
    // void dfs(int i,int j,vector<vector<int>>&grid){
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){
    //         return;
    //     }
    //     grid[i][j]=2;
    //     dfs(i-1,j,grid);
    //     dfs(i+1,j,grid);
    //     dfs(i,j+1,grid);
    //     dfs(i,j-1,grid);
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(grid[i][j]==2){
        //             dfs(i,j,grid);
        //         }
        //     }
        // }
        // int c=0
        queue<pair<int,int>>q;
        int fre=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fre++;
                }
            }
        }
        int time=0;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        while(!q.empty() && fre>0){
            int z=q.size();
            bool rot=false;
            while(z--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                        fre--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        rot=true;
                    }
                }
                
            }
            if(rot){
                time++;
            }
        }
        return fre==0?time:-1;
    }
};