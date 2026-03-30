class Solution {
public:
    vector<int>parent;
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }

    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            parent[py]=px;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        parent.resize(n);
        if(m<n-1){
            return -1;
        }
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &e:connections){
            int u=e[0];
            int v=e[1];
            unite(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i){
                comp++;
            }
        }
        return comp-1;
    }
};