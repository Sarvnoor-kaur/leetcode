class Solution {
public:
    bool check(vector<vector<int>>graph,int curr,vector<int>&color,int currcol){
        color[curr]=currcol;
        for(auto &n:graph[curr]){
            if(color[n]==color[curr]){
                return false;
            }
            if(color[n]==-1){
                int opp=1-currcol;
                if(check(graph,n,color,opp)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(check(graph,i,color,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};