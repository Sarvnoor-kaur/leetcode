class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        
        map<int, vector<pair<int,int>>> mp;
        mp[1] = {{0,-1},{0,1}};
        mp[2] = {{-1,0},{1,0}};
        mp[3] = {{0,-1},{1,0}};
        mp[4] = {{0,1},{1,0}};
        mp[5] = {{0,-1},{-1,0}};
        mp[6] = {{0,1},{-1,0}};
        
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            if(x == m-1 && y == n-1)
                return true;
            
            for(auto &d : mp[grid[x][y]]){
                int nx = x + d.first;
                int ny = y + d.second;
                
                if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny])
                    continue;
                
                for(auto &back : mp[grid[nx][ny]]){
                    if(nx + back.first == x && ny + back.second == y){
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return false;
    }
};