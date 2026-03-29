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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(auto &s:equations){
            string temp=s;
            if(temp[1]=='='){
                int v1=temp[0]-'a';
                int v2=temp[3]-'a';
                unite(v1,v2);
            }
        }

        for(auto &s:equations){
            string temp=s;
            if(temp[1]=='!'){
                int v1=temp[0]-'a';
                int v2=temp[3]-'a';
                if(find(v1)==find(v2)){
                    return false;
                }
            }
        }
        return true;


        
    }
};