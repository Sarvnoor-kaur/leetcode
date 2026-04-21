class Solution {
public:
    vector<int>parent;
    int find(int in){
        if(parent[in]!=in){
            return parent[in]=find(parent[in]);
        }
        return parent[in];
    }
    void unite(int &rx,int& ry){
        int pa=find(rx);
        int pb=find(ry);
        if(pa!=pb){
            parent[pb]=pa;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        // for(auto &vec:allowedSwaps){
        //     int i=vec[0];
        //     int j=vec[1];
        //     swap(source[i],source[j]);
        // }

        // int co=0;
        // for(int i=0;i<source.size();i++){
        //     if(source[i]!=target[i]){
        //         co++;
        //     }
        // }
        // return co;
        int n=source.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
             parent[i]=i;
        }
        for(auto &vec:allowedSwaps){
            int i=vec[0];
            int j=vec[1];
            unite(i,j);
        }
        unordered_map<int,unordered_map<int,int>>mp;
        for(int i=0;i<source.size();i++){
            int root=find(i);
            mp[root][source[i]]++;
        }

        int ans=0;
        for(int i=0;i<target.size();i++){
            int root=find(i);
            if(mp[root][target[i]]>0){
                mp[root][target[i]]--;
            }else{
                ans++;
            }
        }
        return ans;


    }
};