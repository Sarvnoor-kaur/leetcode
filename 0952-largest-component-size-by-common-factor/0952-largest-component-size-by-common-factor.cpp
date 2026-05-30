class Solution {
public:
    int find(int i,vector<int>&parent){
        if(parent[i]!=i){
            parent[i]=find(parent[i],parent);
        }
        return parent[i];
    }
    void Union(int x,int y,vector<int>&rank,vector<int>&parent){
        int px=find(x,parent);
        int py=find(y,parent);
        if(px!=py){
            if(rank[px]>rank[py]){
                parent[py]=px;
            }else if(rank[px]<rank[py]){
                parent[px]=py;
            }else{
                parent[py]=px;
                rank[px]++;
            }
        }
    }
    int largestComponentSize(vector<int>& nums) {
        // int n=nums.size();
        // 
        // for(int i=0;i<n;i++){
        //     parent[i]=i;
        // }
        int mxi=*max_element(nums.begin(),nums.end());
        vector<int>rank(mxi+1,0);

        vector<int>parent(mxi+1);
        for(int i=1;i<=mxi;i++){
            parent[i]=i;
        }

        for(int num:nums){
            for(int f=2;f*f<=num;f++){
                if(num%f==0){
                    Union(num,f,rank,parent);
                    Union(num,num/f,rank,parent);
                }
            }
        }
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int num:nums){
            int p=find(num,parent);
            mp[p]++;
            maxi=max(maxi,mp[p]);
        }
        return maxi;

        
    }
};