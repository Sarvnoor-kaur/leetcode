class Solution {
public:
    bool solve(int i,int j,int pi,int pj,vector<vector<char>>& grid,vector<vector<bool>>&visited,int st){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=st){
            return false;
        }
        if(visited[i][j])return true;
        visited[i][j]=true;
        if(!(i-1==pi && j==pj)){
            if(solve(i-1,j,i,j,grid,visited,st)){
                return true;
            }
        }
        if(!(i+1==pi && j==pj)){
            if(solve(i+1,j,i,j,grid,visited,st)){
                return true;
            }
        }
         if(!(i==pi && j-1==pj)){
            if(solve(i,j-1,i,j,grid,visited,st)){
                return true;
            }
        }
         if(!(i==pi && j+1==pj)){
            if(solve(i,j+1,i,j,grid,visited,st)){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]){
                    if(solve(i,j,-1,-1,grid,visited,grid[i][j])){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};