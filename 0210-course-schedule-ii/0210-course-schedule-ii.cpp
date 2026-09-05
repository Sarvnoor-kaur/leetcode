class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // int n=numCourses.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        vector<int>an;
        for(auto & p:prerequisites){
            int e=p[0];
            int f=p[1];
            adj[f].push_back(e);
            indeg[e]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            an.push_back(v);
            for(int ne:adj[v]){
                indeg[ne]--;
                if(indeg[ne]==0){
                    q.push(ne);
                }
            }
        }
        if(an.size()!=numCourses){
            return {};
        }
        return an;

    }
};