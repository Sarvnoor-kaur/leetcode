class Solution {
public:
    vector<int>parent,rank;
    int find(int i){
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }
    void unite(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)return ;
        if(rank[pa]<rank[pb]){
            parent[pa]=pb;
        }else if(rank[pa]>rank[pb]){
            parent[pb]=pa;
        }else{
            parent[pb]=pa;
            rank[pa]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n,0);
        vector<vector<int>>adj(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        // for(auto &e:stones){
        //     int u=e[0];
        //     int v=e[1];
        //     adj[u][v]=1;
        // }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    unite(i,j);
                }
            }
        }

        int comp=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                comp++;
            }
        }
        return n-comp;

        
    }
};