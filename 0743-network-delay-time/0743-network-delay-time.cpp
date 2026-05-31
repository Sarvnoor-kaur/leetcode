class Solution {
public:
    using pi=pair<int,int>;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // i m gonna die noww dijistraaazzz 
        // vector<pair<int,pair<int,int>>>adj(n+1);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:times){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int adjnode=it.first;
                int w=it.second;
                if(d+w<dist[adjnode]){
                    dist[adjnode]=d+w;
                    pq.push({d+w,adjnode});
                }
            }
        }
        int maxi=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }else{
                maxi=max(maxi,dist[i]);
            }
        }
        return maxi;



        
    }
};