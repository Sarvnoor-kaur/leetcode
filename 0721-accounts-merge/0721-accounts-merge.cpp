class Solution {
public:
    vector<int>parent;

    int find(int i){
        if(i==parent[i]){
            return i;     
        }
        return find(parent[i]);
    }

    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            parent[px]=py;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n=accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mp.count(email)){
                    unite(i,mp[email]);
                }else{
                    mp[email]=i;
                }
            }
        }
        unordered_map<int,set<string>>m;
        for(auto &p:mp){
            string email=p.first;
            int idx=p.second;
            int root=find(idx);
            m[root].insert(email);
        }

        vector<vector<string>>ans;
        for(auto & p:m){
            vector<string>temp;
            int i=p.first;
            temp.push_back(accounts[i][0]);
            for(auto &c:p.second){
                temp.push_back(c);
            }
            ans.push_back(temp);

        }
        return ans;
        
    }
};