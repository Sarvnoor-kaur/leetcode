class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long ts=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ts+=grid[i][j];
            }
        }
        
        if(ts%2!=0)return false;
        long long half=ts/2;
        long long rs=0;
        for(auto &vec:grid){
            long long sum=accumulate(vec.begin(),vec.end(),0LL);
            rs+=sum;
            if(rs==half)return true;
        }
        // vertical;
        long long cs=0;
        for(int j=0;j<grid[0].size();j++){
            long long cs1=0;
            for(int i=0;i<grid.size();i++){
                cs1+=grid[i][j];
            }
            cs+=cs1;
            if(cs==half)return true;
        }
        return false;
        
    }
};