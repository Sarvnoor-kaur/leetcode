class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int>flat;
        for(auto& row:grid){
            for(auto & col:row){
                flat.push_back(col);
            }
        }

        int b=flat[0];
        for(auto &f:flat){
            if(abs(f-b)%x!=0){
                return -1;
            }
        }
        sort(flat.begin(),flat.end());
        int n=flat.size();
        int op=0;
        int med=flat[n/2];
        for(auto &v:flat){
            op+=abs(v-med)/x;
        }
        return op;
    }
};