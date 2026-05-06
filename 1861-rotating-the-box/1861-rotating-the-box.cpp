class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>>trans(boxGrid[0].size(),vector<char>(boxGrid.size()));
        for(int i=0;i<boxGrid[0].size();i++){
            for(int j=0;j<boxGrid.size();j++){
                trans[i][j]=boxGrid[j][i];
            }
        }

        for(auto &r:trans){
            reverse(r.begin(),r.end());
        }
        int n=trans.size();
        for(int j=0;j<trans[0].size();j++){
            int step=n-1;
            for(int i=n-1;i>=0;i--){
                if(trans[i][j]=='*'){
                    step=i-1;
                    continue;
                }
                if(trans[i][j]=='#'){
                    
                    trans[i][j]='.';
                    trans[step][j]='#';
                    step--;
                }
            }
        }
        return trans;
        
    }
};