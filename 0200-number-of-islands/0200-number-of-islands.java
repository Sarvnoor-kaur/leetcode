class Solution {
    public void df(int i,int j,int m,int n,char[][]grid){
        if(i<0||j<0||i>=n||j>=m||grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        df(i-1,j,m,n,grid);
        df(i,j-1,m,n,grid);
        df(i+1,j,m,n,grid);
        df(i,j+1,m,n,grid);
    }
    public int numIslands(char[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    c++;
                    df(i,j,m,n,grid);
                }
            }
        }
        return c;
    }
}