class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int ize=grid.size()*grid[0].size();
        vector<int>hi(ize);
        k=k%ize;
        int z=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                hi[(z+k)%ize]=grid[i][j];
                z++;
            }
        }
        int m=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=hi[m];
                m++;
            }
        }
        return grid;
    }
};