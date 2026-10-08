class Solution {
public:
    int find(int i,vector<int>&parent){
        if(parent[i]!=i){
            return parent[i]=find(parent[i],parent);
        }
        return parent[i];
    }
    void unite(int i ,int j, vector<int>&parent){
        int u=find(i,parent);
        int v=find(j,parent);
        if(u!=v){
            parent[v]=u;
        }
    }
    bool similar(string one,string two){
        int c=0;
        for(int i=0;i<one.size();i++){
            if(one[i]!=two[i]){
                c++;
            }
        }
        if(c>2){
            return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    unite(i,j,parent);
                }
            }
        }
        int g=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                g++;
            }
        }
        return g;
    }
};