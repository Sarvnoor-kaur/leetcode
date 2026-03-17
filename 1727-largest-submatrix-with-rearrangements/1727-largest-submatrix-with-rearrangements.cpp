class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>height=matrix;
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    height[i][j]=matrix[i][j]+height[i-1][j];
                }
            }
        }
        int maxi=0;
        for(auto &vec:height){
            sort(vec.begin(),vec.end(),greater());
            int j=1;
            for(int i=0;i<vec.size();i++){
                maxi=max(maxi,vec[i]*j);
                j++;
            }
        }
        return maxi;
        
    }
};