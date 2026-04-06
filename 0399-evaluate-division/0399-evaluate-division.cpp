class Solution {
public:
    double dfs(string src,string des,unordered_set<string>vis,unordered_map<string,vector<pair<string,double>>>&graph){
        if(graph.find(src)==graph.end())return -1.0;
        if(src==des)return 1.0;
        vis.insert(src);
        for(auto &nbr:graph[src]){
            string next=nbr.first;
            double w=nbr.second;
            if(vis.count(next))continue;
            double ans=dfs(next,des,vis,graph);
            if(ans!=-1.0){
                return w*ans;
            } 
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,vector<pair<string,double>>>graph;
        int i=0;
        for(auto &e:equations){
            string a=e[0];
            string b=e[1];
            double val=values[i];
            i++;
            graph[a].push_back({b,val});
            graph[b].push_back({a,1/val});
        }
        vector<double>ans;
        for(auto &q:queries){
            string src=q[0];
            string des=q[1];
            unordered_set<string>vis;
            ans.push_back(dfs(src,des,vis,graph));
        }
        return ans;
        
    }
};