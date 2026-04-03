class Solution {
public:
    int m;
    int dfs(int i ,int j,vector<vector<int>>&grid,int id){
        if(i<0 || j<0 ||i>=m||j>=m ||grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=id;
        return 1+dfs(i-1,j,grid,id)+
        dfs(i,j-1,grid,id)+
        dfs(i+1,j,grid,id)+
        dfs(i,j+1,grid,id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        m=grid.size();
        unordered_map<int,int>size;
        int id=2;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    size[id]=dfs(i,j,grid,id);
                    id++;
                }
            }
        }
        int maxi=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    if(i>0) st.insert(grid[i-1][j]);
                    if(j>0) st.insert(grid[i][j-1]);
                    if(i<m-1) st.insert(grid[i+1][j]);
                    if(j<m-1) st.insert(grid[i][j+1]);

                    int val=1;
                    for(auto &s:st){
                        val+=size[s];
                    }
                    maxi=max(maxi,val);

                }
            }
        }
        for(auto &it:size){
            maxi=max(maxi,it.second);
        }
        return maxi;
        
    }
};