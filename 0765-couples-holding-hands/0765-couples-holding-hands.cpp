class Solution {
public:
    vector<int>parent;
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px!=py){
            parent[px]=py;
        }
    }
    int minSwapsCouples(vector<int>& row) {
        
        int couples=row.size()/2;
        int n=row.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<row.size();i+=2){
            int c1=row[i]/2;
            int c2=row[i+1]/2;
            unite(c1,c2);
        }

        int comp=0;
        for(int i=0;i<row.size();i++){
            if(parent[i]==i){
                comp++;
            }
        }
        return n-comp;

    }
};