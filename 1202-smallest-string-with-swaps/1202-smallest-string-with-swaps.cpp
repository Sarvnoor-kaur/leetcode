class Solution {
public:
    vector<int>parent;
    int find(int in){
        if(parent[in]!=in){
            return parent[in]=find(parent[in]);
        }
        return parent[in];
    }
    void unite(int rx,int ry){
        int pa=find(rx);
        int pb=find(ry);
        if(pa!=pb){
            parent[pb]=pa;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        parent.resize(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &p:pairs){
            int i=p[0];
            int j=p[1];
            unite(i,j);
        }
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>>mp;
        for(int i=0;i<s.size();i++){
            int root=find(i);
            mp[root].push(s[i]);
        }

        string ans="";
        for(int i=0;i<n;i++){
            int root=find(i);
            ans+=mp[root].top();
            mp[root].pop();
        }
        return ans;
    }
};