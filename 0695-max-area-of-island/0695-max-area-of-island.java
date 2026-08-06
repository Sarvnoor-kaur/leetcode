class Solution {
    public void df(int i,int j,int m,int n,int [][] grid,int []c){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]==0){
            return ;
        }
        c[0]++;
        grid[i][j]=0;
        df(i+1,j,m,n,grid,c);
        df(i-1,j,m,n,grid,c);
        df(i,j-1,m,n,grid,c);
        df(i,j+1,m,n,grid,c);
        // return c;
    }
    public int maxAreaOfIsland(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        int maxi=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1){
                    // int c=0;
                    int[] c=new int[1];
                    df(i,j,m,n,grid,c);
                    maxi=Math.max(maxi,c[0]);
                }
            }
        }
        return maxi;
    }
}