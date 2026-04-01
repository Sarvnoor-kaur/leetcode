class Solution {
public:
    int m,n;
    // int n=board[0].size();
    void dfs(int i,int j,vector<vector<char>>&board){
        
       if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
            return;
        }
        board[i][j]='A';
        dfs(i-1,j,board);
        dfs(i,j-1,board);
        dfs(i+1,j,board);
        dfs(i,j+1,board);

    }
    void solve(vector<vector<char>>& board) {

        m=board.size();
        n=board[0].size();
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board);
            }
            if(board[m-1][j]=='O'){
                dfs(m-1,j,board);
            }
        }

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
        
    }
};