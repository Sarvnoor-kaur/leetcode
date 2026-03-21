class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        // vector<vector<int>>mat(k-1,vector<int>(k-1));
        // for(int i=x;i<k;i++){
        //     for(int j=y;j<k;j++){
        //         mat[i][j]=grid[i][j];
        //     }
        // }

        // for(auto & coll:mat){
            
        // }

        int top=x,bot=x+k-1;
        while(top<bot){
            for(int col=y;col<y+k;col++){
                swap(grid[top][col],grid[bot][col]);
            }
            top++;
            bot--;
        }
        return grid;

    }
};