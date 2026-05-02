class Solution {
public:
    bool dfs(int i,int j,vector<vector<char>>& board,string word,int in){
        if(in==word.size())return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[in]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        bool found=dfs(i-1,j,board,word,in+1)||
                   dfs(i+1,j,board,word,in+1)||
                    dfs(i,j-1,board,word,in+1)||
                    dfs(i,j+1,board,word,in+1);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};