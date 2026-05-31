class Solution {
public:
    int find(int i,vector<int>&parent){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i],parent);
    }
    bool unite(int u,int v,vector<int>&parent,vector<int>&rank){
        int pu=find(u,parent);
        int pv=find(v,parent);
        if(pu==pv){
            return false;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else {
            parent[pu]=pv;
            rank[pv]++;
        }
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // sort(points.begin(),points.end());
        // int i=0;
        // int j=1;
        // int pl=0;
        // while(j<points.size()){
        //     int x1=points[i][0];
        //     int y1=points[i][1];
        //     int x2=points[j][0];
        //     int y2=points[j][1];
        //     int f=abs(x2-x1);
        //     int u=abs(y2-y1);
        //     int um=f+u;
        //     pl+=um;
        //     i++;
        //     j++;
        // }
        // return pl;
        int n=points.size();
        vector<int>parent(n+1);
        vector<int>rank(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>>edge;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1]; 
                int f=abs(x2-x1);
                int u=abs(y2-y1);
                int um=f+u;
                edge.push_back({um,i,j});
            }
        }
        sort(edge.begin(),edge.end());
        int mt=0;
        for(auto &e:edge){
            int w=e[0];
            int u=e[1];
            int v=e[2];
            if(unite(u,v,parent,rank)){
                mt+=w;
            }
        }
        return mt;
    }
};