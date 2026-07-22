class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fre=0;
        queue<pair<int,int>>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    pq.push({i,j});
                }else if(grid[i][j]==1){
                    fre++;
                }
            }
        }
        int time=0;

        int dirx[4]={-1,1,0,0};
        int diry[4]={0,0,-1,1};
        while(!pq.empty()){
            int z=pq.size();
            bool rot=false;
            while(z--){
                auto [x,y]=pq.front();
                pq.pop();
                for(int i=0;i<4;i++){
                    int dx=x+dirx[i];
                    int dy=y+diry[i];
                    if(dx>=0 && dy>=0 && dx<m && dy<n && grid[dx][dy]==1){
                        rot =true;
                        fre--;
                        pq.push({dx,dy});
                        grid[dx][dy]=2;
                    }

                }
            }
            if(rot==true){
                time++;
            }
        }
        return fre==0?time:-1;
    }
};