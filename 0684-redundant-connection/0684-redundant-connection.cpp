class Solution {
public:
    bool Union(int rootx,int rooty,vector<int>&parent){
        if(rootx==rooty){
            return false;
        }
        
        parent[rootx]=rooty;
        return true;
       
    }
    int find(int i,vector<int>&parent){
        if(parent[i]==i){
            return i;
        }
        return parent [i]=find(parent[i],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int rootx=find(u,parent);
            int rooty=find(v,parent);
            if(!Union(rootx,rooty,parent)){
                return {u,v};
            }
        }
        return {};
    }
};