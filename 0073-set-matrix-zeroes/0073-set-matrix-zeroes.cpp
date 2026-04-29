class Solution {
public:
    void solve(int i,int j,vector<vector<int>>&matrix,int dir){
        int m=matrix.size();
        int n=matrix[0].size();
        if(i<0||j<0||i>=m||j>=n){
            return ;
        }
        matrix[i][j]=0;
        if(dir==0){
            solve(i-1,j,matrix,0);
        }else if(dir==1){
            solve(i+1,j,matrix,1);
        }else if(dir==2){
            solve(i,j-1,matrix,2);
        }else if(dir==3){
            solve(i,j+1,matrix,3);
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<pair<int,int>>p;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    p.push_back({i,j});
                }
            }
        }
        for(auto&m:p){
            int i=m.first;
            int j=m.second;
            solve(i-1,j,matrix,0);
            solve(i+1,j,matrix,1);
            solve(i,j-1,matrix,2);
            solve(i,j+1,matrix,3);
        }

    }
};