class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegre(numCourses,0);
        for(auto &p:prerequisites){
            int f=p[0];
            int se=p[1];
            adj[se].push_back(f);
            indegre[f]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto &neigh:adj[node]){
                indegre[neigh]--;
                if(indegre[neigh]==0){
                    q.push(neigh);
                }
            }
            
        }
        return count==numCourses;
    }
};